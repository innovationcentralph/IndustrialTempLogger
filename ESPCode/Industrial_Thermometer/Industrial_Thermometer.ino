// this example is public domain. enjoy! https://learn.adafruit.com/thermocouple/
#include "UserConfig.h"
#include "SystemConfig.h"
#include "Wifi.h"
#include "HTTPSClient.h"
#include "max6675.h"

#define thermoDO1  32
#define thermoDO2  33
#define thermoDO3  25
#define thermoDO4  26
#define thermoDO5  27
#define thermoDO6  14
#define thermoCS   23
#define thermoCLK  19

MAX6675 thermocouple1(thermoCLK, thermoCS, thermoDO1);
MAX6675 thermocouple2(thermoCLK, thermoCS, thermoDO2);
MAX6675 thermocouple3(thermoCLK, thermoCS, thermoDO3);
MAX6675 thermocouple4(thermoCLK, thermoCS, thermoDO4);
MAX6675 thermocouple5(thermoCLK, thermoCS, thermoDO5);
MAX6675 thermocouple6(thermoCLK, thermoCS, thermoDO6);

Wifi Wifi(wifiSSID, wifiPASS);
HTTPSClient HTTPSClient;
float multipler[7] = {0, 0, 0, 0, 0, 0, 0};




void setup() {
  Serial.begin(9600);

  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);

  Wifi.connect();
  Serial.print("referenceValue C = ");
  delay(5000);
  referenceValue = thermocouple6.readCelsius();
  Serial.println(referenceValue);


}

void loop() {
  // basic readout test, just print the current temp

  Serial.print("thermocouple1 C = ");
  Temp1 = thermocouple1.readCelsius();
  Serial.println(Temp1);
  delay(250);

  Serial.print("thermocouple2 C = ");
  Temp2 = thermocouple2.readCelsius();
  Serial.println(Temp2);
  delay(250);

  Serial.print("thermocouple3 C = ");
  Temp3 = thermocouple3.readCelsius();
  Serial.println(Temp3);
  delay(250);

  Serial.print("thermocouple4 C = ");
  Temp4 = thermocouple4.readCelsius();
  Serial.println(Temp4);
  delay(250);

  Serial.print("thermocouple5 C = ");
  Temp5 = thermocouple5.readCelsius();
  Serial.println(Temp5);
  delay(250);

  Serial.print("thermocouple6 C = ");
  Temp6 = thermocouple6.readCelsius();
  Serial.println(Temp6);
  delay(250);

  Serial.println("");
  // For the MAX6675 to update, you must delay AT LEAST 250ms between reads!
  delay(1000);

  if (millis() - sendMillis >= SEND_SENSOR_INTERVAL) {
    Serial.println("SENDING DATA");
    String URL = ("https://innovationcentralph.com/templogger/resources/data/APIsensorlog.php?id=ABC123&t=" + String(Temp1) + ","  + String(Temp2) + ","  + String(Temp3) + ","  + String(Temp4) + ","  + String(Temp5) + ","  + String(Temp6) + "&json=1");
    String httpsResponse = HTTPSClient.SendGetRequest(URL, false);
    Serial.println("HTTPS RESPONSE: " + httpsResponse);
    sendMillis = millis();
  }
}


//float calibrateOnePoint(float rawValue) {
//  // Map the raw value to the calibrated range
//  Serial.println("");
//  Serial.println("rawValue" + String(rawValue));
//  float calibratedValue =rawValue* multipler[number];
//  Serial.println("calibratedValue" + String(calibratedValue));
//  return calibratedValue;
//}
//
//void multiplier(float rawValue, byte number) {
//  // Map the raw value to the calibrated range
//  multipler[number] = referenceValue / rawValue;
//}
