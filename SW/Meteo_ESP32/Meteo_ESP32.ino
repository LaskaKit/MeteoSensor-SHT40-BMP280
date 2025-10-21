/*
* This example code is used for LaskaKit ESP32-DEVKit board https://www.laskakit.cz/laskakit-esp32-devkit/
* with our Meteo Sensor, Temperature Humidity and Pressure module  https://www.laskakit.cz/laskakit-outdoor-meteo-thp-senzor-sht40-bmp280/
*
*
* Made by (c) laskakit.cz 2025
*
*/
 
#include <Wire.h>
#include "Adafruit_SHT4x.h"
#include <SPI.h>
#include <Adafruit_BMP280.h>

#define PIN_ON 2

Adafruit_SHT4x sht4 = Adafruit_SHT4x();
Adafruit_BMP280 bmp; // use I2C interface
Adafruit_Sensor *bmp_temp = bmp.getTemperatureSensor();
Adafruit_Sensor *bmp_pressure = bmp.getPressureSensor();

void setup() {

  Serial.begin(115200);
  pinMode(PIN_ON, OUTPUT);      // Set EN pin for second stabilisator as output
  digitalWrite(PIN_ON, HIGH);   // Turn on the second stabilisator

  Wire.begin();

  while (!Serial) 
  {
    ; // wait for serial
  }
 
  Serial.println(F("BMP280 Sensor event test"));

  unsigned status;
  //status = bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID);
  status = bmp.begin();
  if (!status) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
    Serial.print("SensorID was: 0x"); Serial.println(bmp.sensorID(),16);
    Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
    Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    Serial.print("        ID of 0x61 represents a BME 680.\n");
    while (1) delay(10);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  bmp_temp->printSensorDetails();


 Serial.println(F("SHT Sensor test"));

  if (! sht4.begin()) 
  {
    Serial.println("SHT4x not found");
    Serial.println("Check the connection");
    while (1) delay(1);
  }
 
  sht4.setPrecision(SHT4X_HIGH_PRECISION); // highest resolution
  sht4.setHeater(SHT4X_NO_HEATER); // no heater
 
}
 
void loop() {
  sensors_event_t humidity, temp; // temperature and humidity variables
 
  sht4.getEvent(&humidity, &temp);
  Serial.println("SHT: ");
  Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degC");
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");

  sensors_event_t temp_event, pressure_event;
  bmp_temp->getEvent(&temp_event);
  bmp_pressure->getEvent(&pressure_event);
 
  Serial.println("BMP: ");
  Serial.print(F("Temperature = "));
  Serial.print(temp_event.temperature);
  Serial.println(" *C");

  Serial.print(F("Pressure = "));
  Serial.print(pressure_event.pressure);
  Serial.println(" hPa");

  delay(2000);
}
