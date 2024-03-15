#ifndef MQTTHANDLER_H
#define MQTTHANDLER_H

#include <WiFi.h>
#include <PubSubClient.h>

class MQTTHandler
{
public:
  MQTTHandler(const char* server, const char* mqttUser, const char* mqttPassword, const char* mqttID);

  void setup();
  void connect();
  void loop();
  void handle_message(char* topic, byte* payload, unsigned int length);
  void set_subscribe_topics(const char* topics[], int num_topics);
  void publish(const char* topic, const char* message);
  void mqtt_reconnect();
  void handle_callback();

  void set_message_callback(void (*callback)(char*, byte*, unsigned int))
  {
    message_callback_ = callback;
  }

  void setLedIndicator(byte pin);


private:

  void (*message_callback_)(char*, byte*, unsigned int);

  WiFiClient wifiClient_;
  PubSubClient client_;
  const char* server_;
  const char* mqttUser_;
  const char* mqttPassword_;
  const char* mqttID_;
  const char** subscribe_topics_;
  int num_subscribe_topics_;

  byte _pin;
  bool indicatorInitialized = false;

  void subscribe();
};

#endif
