#include "MQTTHandler.h"

MQTTHandler::MQTTHandler(const char* server, const char* mqttUser, const char* mqttPassword, const char* mqttID)
{
  client_ = wifiClient_;
  server_       = server;
  mqttUser_     = mqttUser;
  mqttPassword_ = mqttPassword;
  mqttID_         = mqttID; 
  subscribe_topics_ = NULL;
  num_subscribe_topics_ = 0;
}


void MQTTHandler::setup()
{

  client_.setServer(server_, 18933);
  client_.setCallback([this](char* topic, byte* payload, unsigned int length) {
    this->handle_message(topic, payload, length);
  });
}

void MQTTHandler::connect()
{
  while (!client_.connected())
  {
    Serial.println("Connecting to MQTT broker...");
    if (client_.connect(mqttID_, mqttUser_, mqttPassword_))
    {
      Serial.println("Connected to MQTT broker");
      Serial.println("Printing Subs");
      subscribe();
    }
    else
    {
      Serial.print("Failed with state ");
      Serial.print(client_.state());
      delay(2000);
    }
  }
}

void MQTTHandler::loop()
{
  if (!client_.connected())
  {
    if(indicatorInitialized){
      digitalWrite(_pin, LOW);
    }
    mqtt_reconnect();
  }else{
    if(indicatorInitialized){
      digitalWrite(_pin, HIGH);
    }
  }
  client_.loop();
}

void MQTTHandler::subscribe()
{
  for (int i = 0; i < num_subscribe_topics_; i++)
  {
    client_.subscribe(subscribe_topics_[i]);
  }
}

void MQTTHandler::set_subscribe_topics(const char* topics[], int num_topics)
{
  subscribe_topics_ = topics;
  num_subscribe_topics_ = num_topics;
}

void MQTTHandler::publish(const char* topic, const char* message)
{
  client_.publish(topic, message);
}

void MQTTHandler::setLedIndicator(byte pin){
  _pin = pin;
  pinMode(_pin, OUTPUT);
  indicatorInitialized = true;
}

void MQTTHandler::mqtt_reconnect()
{
  while (!client_.connected())
  {
    Serial.println("Attempting MQTT connection...");
    if (client_.connect(mqttID_, mqttUser_, mqttPassword_))
    {
      Serial.println("connected to MQTT broker");
      subscribe();
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client_.state());
      Serial.println(" retrying in 5 seconds");
      delay(5000);
    }
  }
}

void MQTTHandler::handle_message(char* topic, byte* payload, unsigned int length)
{
//  Serial.print("Message arrived [");
//  Serial.print(topic);
//  Serial.print("]: ");
//
//  String message = "";
//  for (int i = 0; i < length; i++)
//  {
//    message += (char)payload[i];
//  }

//  Serial.println(message);

  if (message_callback_ != NULL) {
    message_callback_(topic, payload, length);
  }
}
