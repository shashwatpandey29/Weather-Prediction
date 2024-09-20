import joblib
import numpy as np

# Load the saved model
model = joblib.load('pressure_prediction_model.pkl')

# Function to predict pressure based on temperature and humidity
def predict_pressure(temperature, humidity):
    features = np.array([[temperature, humidity]])
    predicted_pressure = model.predict(features)
    return predicted_pressure[0]

# Example usage
temperature = 25.0  # example temperature
humidity = 60.0     # example humidity
predicted_pressure = predict_pressure(temperature, humidity)
print(f"Predicted Pressure: {predicted_pressure}")
