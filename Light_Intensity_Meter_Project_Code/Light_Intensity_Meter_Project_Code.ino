#include <Wire.h>         // Adds I2C library 
#include <BH1750.h>       // Adds BH1750 library file 

#define BLYNK_PRINT Serial

// Initializing Template created on Blynk IoT
#define BLYNK_TEMPLATE_ID "TMPLPmISTDdM"

// Initializing Wi-Fi
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Declaring Wi-Fi Connection
char auth[] = "Pwgm23Wmw_6SNHoTAXHIrnUt1ZDtug2v" ; 
char ssid[] = "OPPO A5s";
char pass[] = "03453358461";

BH1750 lightMeter;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  Blynk.begin(auth, ssid, pass);
  lightMeter.begin();
}

void loop()
{
  Blynk.run();
  delay(1000);
  float lux = lightMeter.readLightLevel();
  Blynk.virtualWrite(V0, lux);
}
