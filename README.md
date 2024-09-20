---

# Weather Monitoring System with Blynk and Flask Dashboard

This project creates a real-time weather monitoring system using the **ESP8266**, multiple sensors (DHT11, BMP180, rain sensor, LDR sensor), and displays the collected data on both a **Blynk mobile app** and a **Flask web dashboard**. Additionally, it includes a **machine learning model** for predicting atmospheric pressure based on temperature and humidity, and displays this prediction on the dashboard.

## Features
- Collects real-time weather data such as:
  - Temperature
  - Humidity
  - Rain percentage
  - Atmospheric Pressure
  - Altitude
  - Light Intensity (LDR sensor)
- Displays real-time data on a **Blynk mobile app**.
- Predicts atmospheric pressure using a **machine learning model** based on temperature and humidity.
- Displays real-time and predicted data on a **Flask web dashboard**.
- Easily customizable and scalable.

## Components Used
- **ESP8266** (NodeMCU) as the microcontroller.
- **DHT11 Sensor** for temperature and humidity.
- **BMP180 Sensor** for pressure and altitude.
- **Rain Sensor** to detect moisture/rainfall.
- **LDR Sensor** to detect light intensity.
- **LiquidCrystal I2C** for displaying data on an LCD screen.

## Requirements

### Hardware
- ESP8266 (NodeMCU)
- DHT11 Sensor
- BMP180 Sensor
- Rain Sensor
- LDR Sensor
- LCD I2C Display

### Software
- Arduino IDE
- Python 3.x
- Blynk app for Android/iOS
- Flask for the web dashboard

## How It Works

1. **ESP8266** collects data from the connected sensors: temperature and humidity from DHT11, pressure and altitude from BMP180, rainfall from the rain sensor, and light intensity from the LDR sensor.
2. The data is sent to the **Blynk cloud** via the ESP8266, allowing real-time display of sensor values on the Blynk mobile app.
3. The **Flask web dashboard** collects the same data by fetching it from the Blynk server and displays it in a visually appealing format.
4. A **machine learning model** predicts atmospheric pressure based on the temperature and humidity readings, and this prediction is shown on the web dashboard alongside the real-time data.

## Running the Project

### 1. Upload the Arduino code to the ESP8266
- Use **Arduino IDE** to upload the weather monitoring code to the **ESP8266**. Ensure that all libraries for the sensors (DHT, BMP180) and Blynk are installed.
  
### 2. Set up the Python environment
- Install Python dependencies like Flask, scikit-learn, requests, and numpy.
- Set up a machine learning model for predicting pressure based on temperature and humidity data. The model will be trained with example data and can be updated for more accurate predictions.
  
### 3. Create the Flask web dashboard
- The dashboard will fetch sensor data from the Blynk cloud and display it in real time.
- Predicted pressure values from the machine learning model will be calculated and shown alongside the real-time data.

### 4. Running the Flask app
- Launch the Flask server to make the dashboard accessible in a browser.
- View the dashboard and observe real-time data and predictions from any device connected to the same network.

## Key Features of the Dashboard
- **Real-time Data Display**: Displays real-time values for temperature, humidity, rain, altitude, and light intensity.
- **Pressure Prediction**: Shows the predicted atmospheric pressure based on real-time sensor data.
- **Mobile and Web Integration**: Seamless integration between the Blynk mobile app and a custom web dashboard.

## Conclusion

This project provides a comprehensive and scalable solution for real-time weather monitoring with predictive analytics. The combination of Blynk for mobile app functionality and Flask for a personalized web dashboard makes it easy to monitor environmental conditions from anywhere. With predictive capabilities, users can gain additional insights into atmospheric pressure trends, making it useful for weather analysis and forecasting applications.

---
