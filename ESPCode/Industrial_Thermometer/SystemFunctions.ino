////void readSensors() {
////
////  Sensors.PHLevel = phSensor.read();
////
////  Sensors.Humidity    = dht.readHumidity();
////  Sensors.Temperature = dht.readTemperature();
////
////  if (isnan(Sensors.Humidity) || isnan(Sensors.Temperature)) {
////    Serial.println("Failed to read from DHT sensor!");
////  }
////
////  Sensors.WaterLevel = WaterContainer.getProximity();
////  Sensors.WaterLevel = map(Sensors.WaterLevel, WATER_CONTAINER_EMPTY, WATER_CONTAINER_FULL, 0, 100);
////  Sensors.WaterLevel = constrain(Sensors.WaterLevel, 0, 100);
////
////  Sensors.NutrientLevel = NutrientContainer.getProximity();
////  Sensors.NutrientLevel = map(Sensors.NutrientLevel, NUTRIENT_CONTAINER_EMPTY, NUTRIENT_CONTAINER_FULL, 0, 100);
////  Sensors.NutrientLevel = constrain(Sensors.NutrientLevel, 0, 100);
////
////  int rawAmbientLight = analogRead(LDR_PIN);
////
////
////  Serial.println("Raw Ambient = " + String(rawAmbientLight));
////
////  Sensors.AmbientLight  = (rawAmbientLight > AMBIENT_THRESHOLD) ? ON : OFF;
////
////  Sensors.DrainLevel = (digitalRead(DRAIN_LEVEL_PIN) == HIGH) ? ON : OFF;
////
////  Serial.println("Drain Level = " + String(Sensors.DrainLevel));
////  Serial.println("Sensors.WaterLevel = " + String(Sensors.WaterLevel));
////  Serial.println("Sensors.NutrientLevel = " + String(Sensors.NutrientLevel));
////  Serial.println("Sensors.PHLevel = " + String(Sensors.PHLevel));
////  Serial.println("Sensors.AmbientLight = " + String(Sensors.AmbientLight));
////  Serial.println("Sensors.Temperature = " + String(Sensors.Temperature));
////}
////
////void checkThresholds() {
////
////  if (Sensors.Temperature > Thresholds.Temperature.High) {
////    //    Serial.print / ln("---RELAY_TEMP_HIGH, RELAY_ON---");
////    controlRelays(RELAY_TEMP_HIGH, RELAY_ON);
////    controlRelays(RELAY_TEMP_LOW, RELAY_OFF);
////  }
////  else if (Sensors.Temperature < Thresholds.Temperature.Low) {
////    //    Serial.println("---RELAY_TEMP_HIGH, RELAY_OFF---");
////    controlRelays(RELAY_TEMP_HIGH, RELAY_OFF);
////    controlRelays(RELAY_TEMP_LOW, RELAY_ON);
////  }
////  else {
////    //     Serial.println("---RELAY_TEMP_HIGH, ELSE---");
////    controlRelays(RELAY_TEMP_HIGH, RELAY_OFF);
////    controlRelays(RELAY_TEMP_LOW, RELAY_OFF);
////  }
////
////  if (Sensors.PHLevel > Thresholds.PH.High) {
////    //    Serial.println("---RELAY_PH_HIGH, RELAY_ON---");
////    controlRelays(RELAY_PH_HIGH, RELAY_ON);
////    controlRelays(RELAY_PH_LOW, RELAY_OFF);
////  }
////  else if (Sensors.PHLevel < Thresholds.PH.Low) {
////    Serial.println("---RELAY_PH_HIGH, RELAY_OFF---");
////    controlRelays(RELAY_PH_HIGH, RELAY_OFF);
////    controlRelays(RELAY_PH_LOW, RELAY_ON);
////  }
////  else {
////    Serial.println("---RELAY_PH_HIGH, ELSE---");
////    controlRelays(RELAY_PH_HIGH, RELAY_OFF);
////    controlRelays(RELAY_PH_LOW, RELAY_OFF);
////  }
////
////  if (Sensors.DrainLevel == ON) {
////    controlRelays(RELAY_DRAIN_VALVE, RELAY_ON);
////    triggerRelays();
////    Serial.println("---Sensors.DrainLevel == ON---");
////    delay(3000);
////    controlRelays(RELAY_DRAIN_VALVE, RELAY_OFF);
////    triggerRelays();
////    Serial.println("---Sensors.DrainLevel == OFF---");
////  } else {
////    Serial.println("---Sensors.DrainLevel == ELSE---");
////    controlRelays(RELAY_DRAIN_VALVE, RELAY_OFF);
////    triggerRelays();
////  }
////
////}
////
////
////
////
////
//void handle_mqtt_message(char* topic, byte* payload, unsigned int length) {
//  // Handle the incoming message here
//  Serial.println(F("\n---------------------------------------"));
//  Serial.print(F("Topic: "));
//  Serial.print(topic);
//  Serial.print(F("\t Message:  "));
//  String message = "";
//  for (int i = 0; i < length; i++)
//  {
//    message += (char)payload[i];
//  }
//  Serial.println(message);
//  Serial.println(F("---------------------------------------\n"));
//
//  if (strcmp(topic, topics[0]) == 0) {
//    if (strcmp(message.c_str(), "Toggle") == 0) {
//      //      controlRelays(RELAY_DRAIN_VALVE, RELAY_ON);
//      //      triggerRelays();
//      delay(3000);
//      //      controlRelays(RELAY_DRAIN_VALVE, RELAY_OFF);
//      //      triggerRelays();
//    }
//  }
//  else if (strcmp(topic, topics[1]) == 0) {
//    byte MAX_VALUES = 12;
//    float values[MAX_VALUES];
//    //    parseDataFromString(message, values, MAX_VALUES, ',');
//
//    //    updateSystemVariables(message);
//    waterMistingMillis = 0;
//    nutrientMistingMillis = 0;
//  }
//
//}
////
/////* Data parsing functions */
////void parseDataFromString(String input, float* output, byte maxOutput, char delimiter) {
////  byte outputIndex = 0;
////  byte startIndex = 0;
////  byte endIndex = 0;
////
////  Serial.println("PARSING: "  + input);
////
////  while (endIndex >= 0 && outputIndex < maxOutput) {
////    endIndex = input.indexOf(delimiter, startIndex);
////
////    if (endIndex == -1) {
////      endIndex = input.length();
////    }
////
////    String valueString = input.substring(startIndex, endIndex);
////
////
////    if (outputIndex == 4) {
////      TimingConfiguration.Growlight.OnTime = valueString;
////      Serial.println("ON TIME: " + TimingConfiguration.Growlight.OnTime);
////    }
////    if (outputIndex == 5) {
////      TimingConfiguration.Growlight.OffTime = valueString;
////      Serial.println("OFF TIME: " + TimingConfiguration.Growlight.OffTime);
////    }
////
////    if (valueString.length() > 0) {
////      output[outputIndex] = valueString.toFloat();
////      outputIndex++;
////    }
////
////    startIndex = endIndex + 1;
////  }
////
////}
////
////void updateSystemVariables(String data) {
////
////  byte MAX_VALUES = 12;
////  float values[MAX_VALUES];
////  parseDataFromString(data, values, MAX_VALUES, ',');
////
////
////  /* Update RAM Variables */
////  TimingConfiguration.Water.Interval = values[0];
////  TimingConfiguration.Water.Duration = values[1];
////  TimingConfiguration.Nutrient.Interval = values[2];
////  TimingConfiguration.Nutrient.Duration = values[3];
////  TimingConfiguration.Growlight.OnTime   = values[4];
////  TimingConfiguration.Growlight.OffTime  = values[5];
////  Thresholds.PH.High = values[6];
////  Thresholds.PH.Low  = values[7];
////  Thresholds.Temperature.High = values[8];
////  Thresholds.Temperature.Low  = values[9];
////  Thresholds.Humidity.High = values[10];
////  Thresholds.Humidity.Low  = values[11];
////
////  for (int x = 0; x < MAX_VALUES; x++) {
////    Serial.print("Value[" + String(x) + "] = " + String(values[x]) + "\t");
////  }
////  Serial.println();
////}
////
/////* Convert time string to epoch */
////int timeStringToEpoch(String timeStr) {
////
////  int hour = timeStr.substring(0, 2).toInt();
////  int min = timeStr.substring(3, 5).toInt();
////  int sec = timeStr.substring(6, 8).toInt();
////
////  int epoch = (hour * 3600) + (min * 60) + sec;
////  return epoch;
////
////}
////
/////* Shift Register Functions */
////void initRegister(int blinkDelay) {
////  digitalWrite(SR_CS, LOW);
////  shiftOut(SR_DIN, SR_CLK, LSBFIRST, B11111111);
////  digitalWrite(SR_CS, HIGH);
////  delay(blinkDelay);
////
////  digitalWrite(SR_CS, LOW);
////  shiftOut(SR_DIN, SR_CLK, LSBFIRST, B00000000);
////  digitalWrite(SR_CS, HIGH);
////  delay(blinkDelay);
////
////  digitalWrite(SR_CS, LOW);
////  shiftOut(SR_DIN, SR_CLK, LSBFIRST, B11111111);
////  digitalWrite(SR_CS, HIGH);
////  delay(blinkDelay);
////
////  digitalWrite(SR_CS, LOW);
////  shiftOut(SR_DIN, SR_CLK, LSBFIRST, B00000000);
////  digitalWrite(SR_CS, HIGH);
////}
////
////
////void controlRelays(byte channel, bool state) {
////
////  bitWrite(registerData, channel - 1, state);
////  //      printFullBinary(registerData);
////
////
////  //  triggerRelays();
////
////  //resetDataset(DATA_CLEAR);
////
////}
////
////void triggerRelays() {
////  digitalWrite(SR_CS, LOW);
////  shiftOut(SR_DIN, SR_CLK, MSBFIRST, registerData);
////  digitalWrite(SR_CS, HIGH);
////
////  byte FilteredData = registerData | 0x70;
////  printFullBinary(FilteredData);
////  if (FilteredData == 255 && Sensors.DrainLevel == 0) {
////    digitalWrite(ALARM_LED, LOW);
////    Serial.println("ALARM OFF");
////  } else {
////    digitalWrite(ALARM_LED, HIGH);
////    Serial.println("ALARM ON");
////  }
////}
////
////void resetDataset(bool b) {
////  if (b) {
////    registerData = 0;
////  }
////}
////
////void printFullBinary(byte number)
////{
////  for (int bit = 7; bit >= 0; bit--)
////  {
////    Serial.print(bitRead(number, bit));
////  }
////
////  Serial.println();
////}
////
//////LCD Code
////
////void showLCD(int page) {
////  switch (page) {
////    case 1:
////      lcdPh(Sensors.PHLevel);
////      break;
////    case 2:
////      lcdTempAndHumid(Sensors.Temperature, Sensors.Humidity);
////      break;
////    case 3:
////      lcdLight(analogRead(LDR_PIN));
////      break;
////    case 4:
////      lcdWater(Sensors.WaterLevel, Sensors.NutrientLevel);
////      break;
////  }
////}
////
////void lcdTemp(float tempValue) //temp
////{
////  String showTemp = String(tempValue);
////  u8g2.firstPage();
////  do
////  {
////    u8g2.setFont(u8g2_font_fub14_tr);
////    u8g2.setDrawColor(1);
////    u8g2.drawStr(0, 15, "Temperature");
////    u8g2.setFont(u8g2_font_fub17_tf);
////    String Celsius = "°C";
////    Celsius.remove(0, 1);
////    String TemperaturePrint = showTemp + Celsius;
////    u8g2.drawStr(5, 42, TemperaturePrint.c_str());
////
////    u8g2.setFont(u8g2_font_helvB08_te);//u8g2_font_helvB08_tF  u8g2_font_t0_12b_mf
////    u8g2.setDrawColor(1);
////    u8g2.drawFrame(0, 49, 17, 14);
////    u8g2.drawStr(2, 60, "PH");
////
////    u8g2.setDrawColor(1);
////    u8g2.drawBox(18, 49, 33, 14);
////    u8g2.setDrawColor(0);
////    u8g2.drawStr(20, 60, "TEMP");
////
////    u8g2.setDrawColor(1);
////    u8g2.drawFrame(52, 49, 34, 14);
////    u8g2.drawStr(54, 60, "LIGHT");
////
////    u8g2.setDrawColor(1);
////    u8g2.drawFrame(87, 49, 41, 14);
////    u8g2.drawStr(88, 60, "WATER");
////
////  } while (u8g2.nextPage());
////}
////
////
////void lcdPh(float PhValue) //temp
////{
////  String showPh = String(PhValue);
////  u8g2.firstPage();
////  do
////  {
////    u8g2.setFont(u8g2_font_fub14_tr);
////    u8g2.setDrawColor(1);
////    u8g2.drawStr(0, 15, "pH Value");
////    u8g2.setFont(u8g2_font_ncenB18_tf);
////    String PhPrint = showPh + " pH";
////    u8g2.drawStr(5, 42, PhPrint.c_str());
////
////    u8g2.setFont(u8g2_font_helvB08_te);//u8g2_font_helvB08_tF  u8g2_font_t0_12b_mf
////    u8g2.setDrawColor(1);
////    u8g2.drawBox(0, 49, 17, 14);
////    u8g2.setDrawColor(0);
////    u8g2.drawStr(2, 60, "PH");
////
////    u8g2.setDrawColor(1);
////    u8g2.drawFrame(18, 49, 33, 14);
////    u8g2.drawStr(20, 60, "TEMP");
////
////    u8g2.setDrawColor(1);
////    u8g2.drawFrame(52, 49, 34, 14);
////    u8g2.drawStr(54, 60, "LIGHT");
////
////    u8g2.setDrawColor(1);
////    u8g2.drawFrame(87, 49, 41, 14);
////    u8g2.drawStr(88, 60, "WATER");
////
////  } while (u8g2.nextPage());
////}
////
////void lcdLight(int lightValue)
////{
////  String showLight = String(lightValue);
////  u8g2.firstPage();
////  do
////  {
////    u8g2.setFont(u8g2_font_fub14_tr);
////    u8g2.setDrawColor(1);
////    u8g2.drawStr(0, 15, "Light");
////    u8g2.setFont(u8g2_font_ncenB18_tf);
////    if (lightValue >= AMBIENT_THRESHOLD) {
////      u8g2.drawStr(5, 42, "OFF");
////    }
////    else  {
////      u8g2.drawStr(5, 42, "ON");
////    }
////    //    String LightPrint = showLight + " lux";
////    //    u8g2.drawStr(5, 42, LightPrint.c_str());
////
////    u8g2.setFont(u8g2_font_helvB08_te);//u8g2_font_helvB08_tF  u8g2_font_t0_12b_mf
////    u8g2.setDrawColor(1);
////    u8g2.drawFrame(0, 49, 17, 14);
////    u8g2.drawStr(2, 60, "PH");
////
////    u8g2.setDrawColor(1);
////    u8g2.drawFrame(18, 49, 33, 14);
////    u8g2.drawStr(20, 60, "TEMP");
////
////    u8g2.setDrawColor(1);
////    u8g2.drawBox(52, 49, 34, 14);
////    u8g2.setDrawColor(0);
////    u8g2.drawStr(54, 60, "LIGHT");
////
////    u8g2.setDrawColor(1);
////    u8g2.drawFrame(87, 49, 41, 14);
////    u8g2.drawStr(88, 60, "WATER");
////
////  } while (u8g2.nextPage());
////}
////
////
////void lcdWater(int drainValue, int refillValue)
////{
////  String showDrain = String(drainValue);
////  String showRefill = String(refillValue);
////  u8g2.firstPage();
////  do
////  {
////    u8g2.setDrawColor(1);
////    u8g2.setFont(u8g2_font_fub14_tr);
////    u8g2.setDrawColor(1);
////    u8g2.drawStr(0, 15, "Drain");
////    u8g2.drawStr(64, 15, "Refill");
////    u8g2.setFont(u8g2_font_fub17_tf); //u8g2_font_ncenB18_tf
////    u8g2.drawBox(62, 0, 2, 47);
////    String drainPrint = showDrain + "%";
////    String refillPrint = showRefill + "%";
////    u8g2.drawStr(0, 42, drainPrint.c_str());
////    u8g2.drawStr(66, 42, refillPrint.c_str());
////
////    u8g2.setFont(u8g2_font_helvB08_te);//u8g2_font_helvB08_tF  u8g2_font_t0_12b_mf
////    u8g2.setDrawColor(1);
////    u8g2.drawFrame(0, 49, 17, 14);
////    u8g2.drawStr(2, 60, "PH");
////
////    u8g2.setDrawColor(1);
////    u8g2.drawFrame(18, 49, 33, 14);
////    u8g2.drawStr(20, 60, "TEMP");
////
////    u8g2.setDrawColor(1);
////    u8g2.drawFrame(52, 49, 34, 14);
////    u8g2.drawStr(54, 60, "LIGHT");
////
////    u8g2.setDrawColor(1);
////    u8g2.drawBox(87, 49, 41, 14);
////    u8g2.setDrawColor(0);
////    u8g2.drawStr(88, 60, "WATER");
////
////  } while (u8g2.nextPage());
////}
////
////void lcdTempAndHumid(int TempValue, int HumidValue)
////{
////  String showTemp = String(TempValue);
////  String showHumid = String(HumidValue);
////  u8g2.firstPage();
////  do
////  {
////    u8g2.setDrawColor(1);
////    u8g2.setFont(u8g2_font_fub14_tr);
////    u8g2.setDrawColor(1);
////    u8g2.drawStr(0, 15, "Temp");
////    u8g2.drawStr(64, 15, "Humid");
////    u8g2.setFont(u8g2_font_ncenB18_tf);
////    u8g2.drawBox(60, 0, 2, 47);
////    u8g2.setFont(u8g2_font_ncenB18_tf);
////    String Celsius = "°C";
////    Celsius.remove(0, 1);
////    String TempPrint = showTemp + Celsius;
////    String HumidPrint = showHumid + "%";
////    u8g2.drawStr(0, 42, TempPrint.c_str());
////    u8g2.drawStr(62, 42, HumidPrint.c_str());
////
////    u8g2.setFont(u8g2_font_helvB08_te);//u8g2_font_helvB08_tF  u8g2_font_t0_12b_mf
////    u8g2.setDrawColor(1);
////    u8g2.drawFrame(0, 49, 17, 14);
////    u8g2.drawStr(2, 60, "PH");
////
////    u8g2.setDrawColor(1);
////    u8g2.drawBox(18, 49, 33, 14);
////    u8g2.setDrawColor(0);
////    u8g2.drawStr(20, 60, "TEMP");
////
////    u8g2.setDrawColor(1);
////    u8g2.drawFrame(52, 49, 34, 14);
////    u8g2.drawStr(54, 60, "LIGHT");
////
////    u8g2.setDrawColor(1);
////    u8g2.drawFrame(87, 49, 41, 14);
////    u8g2.drawStr(88, 60, "WATER");
////
////  } while (u8g2.nextPage());
////}
