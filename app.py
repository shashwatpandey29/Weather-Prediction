import requests
import time
from flask import Flask, render_template
import numpy as np
from sklearn.linear_model import LinearRegression

# Blynk Auth Token
BLYNK_AUTH = "Your_Blynk_Auth_Token"

# Flask Web Dashboard
app = Flask(__name__)

# Machine Learning Model
def train_model():
    # Example dataset (temperature, humidity) -> pressure
    X = np.array([[20, 70], [25, 65], [30, 60], [35, 55]])  # Features
    y = np.array([1010, 1008, 1005, 1002])  # Target (pressure)
    
    model = LinearRegression()
    model.fit(X, y)
    return model

# Fetch data from Blynk
def get_blynk_data(pin):
    url = f"http://blynk.cloud/external/api/get?token={BLYNK_AUTH}&V{pin}"
    response = requests.get(url)
    return float(response.json())

# Send data to Blynk
def send_blynk_data(pin, value):
    url = f"http://blynk.cloud/external/api/update?token={BLYNK_AUTH}&V{pin}={value}"
    requests.get(url)

# Predict the pressure
def predict_pressure(model, temperature, humidity):
    input_data = np.array([[temperature, humidity]])
    predicted_pressure = model.predict(input_data)
    return predicted_pressure[0]

# Flask route to render the web dashboard
@app.route('/')
def dashboard():
    temperature = get_blynk_data(0)
    humidity = get_blynk_data(1)
    rain = get_blynk_data(2)
    altitude = get_blynk_data(4)
    
    # ML Prediction
    model = train_model()
    predicted_pressure = predict_pressure(model, temperature, humidity)
    
    # Send prediction to Blynk
    send_blynk_data(5, predicted_pressure)
    
    # Display data on dashboard
    return render_template('dashboard.html', 
                           temperature=temperature, 
                           humidity=humidity, 
                           rain=rain, 
                           altitude=altitude, 
                           predicted_pressure=predicted_pressure)

if __name__ == "__main__":
    app.run(debug=True)
