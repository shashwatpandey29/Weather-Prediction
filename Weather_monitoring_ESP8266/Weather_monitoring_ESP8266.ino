#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "Your Template ID"
#define BLYNK_TEMPLATE_NAME "Your Template Name"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <SFE_BMP180.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SFE_BMP180 bmp;

char auth[] = "Your Blynk Auth Token"; 
char ssid[] = "Your WiFi Name"; 
char pass[] = "Your WiFi Password";

DHT dht(D3, DHT11); 
BlynkTimer timer;

#define rain A0
#define light D0

double T, P, A;
char status;

void setup() {
  Serial.begin(9600);
  bmp.begin();
  lcd.init();
  lcd.backlight();
  pinMode(light, INPUT);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  dht.begin();

  lcd.setCursor(0, 0);
  lcd.print("Weather Monitor");
  lcd.setCursor(4, 1);
  lcd.print("System");
  delay(4000);
  lcd.clear();

  timer.setInterval(1000L, DHT11sensor);
  timer.setInterval(1000L, rainSensor);
  timer.setInterval(1000L, pressure);
  timer.setInterval(1000L, LDRsensor);
}

void DHT11sensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(t);

  lcd.setCursor(8, 0);
  lcd.print("H:");
  lcd.print(h);
}

void rainSensor() {
  int value = analogRead(rain);
  value = map(value, 0, 1024, 0, 100);
  Blynk.virtualWrite(V2, value);

  lcd.setCursor(0, 1);
  lcd.print("R:");
  lcd.print(value);
  lcd.print(" ");
}

void pressure() {
  status = bmp.startTemperature();
  if (status != 0) {
    delay(status);
    status = bmp.getTemperature(T);

    status = bmp.startPressure(3); 
    if (status != 0) {
      delay(status);
      status = bmp.getPressure(P, T);
      if (status != 0) {
        A = bmp.altitude(P, 1013.25); 

        Blynk.virtualWrite(V3, P);  
        Blynk.virtualWrite(V4, A);  
        Blynk.virtualWrite(V6, T);  

        lcd.setCursor(0, 1);
        lcd.print("A:");
        lcd.print(A);

        lcd.setCursor(8, 1);
        lcd.print("P:");
        lcd.print(P);
      }
    }
  }
}

void LDRsensor() {
  bool value = digitalRead(light);
  WidgetLED LED(V4);
  if (value == 0) {
    LED.on();
  } else {
    LED.off();
  }
}

void loop() {
  Blynk.run();  
  timer.run();  
}
