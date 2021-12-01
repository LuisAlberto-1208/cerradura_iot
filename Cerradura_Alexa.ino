const int salida = 15;

#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

int contconexion = 0;

const char* ssid = "hippie";
const char* password = "12345678";
WiFiClient  client;

unsigned long previousMillis = 0;

const char* server = "api.thingspeak.com"; 
const char * apiKey ="95E6AQY88ZCZL4BC";         // Write API Key
//float temp = 1, valor2 = 0, valor3 = 0;
const unsigned long ChannelNumber = 1535197;
const unsigned int Number = 1;

void setup() {

  Serial.begin(115200);

  pinMode (2, OUTPUT);
  Serial.println("");  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED and 
  contconexion <50) { 
    ++contconexion;
    delay(500);
    Serial.print(".");  }
  if (contconexion <50) {
      Serial.println("");
      Serial.println("WiFi conectado");  }
  else { 
      Serial.println("");
      Serial.println("Error de conexion");  
  }
  ThingSpeak.begin(client);

  pinMode(salida, OUTPUT);
  digitalWrite(salida, HIGH);
}

void loop() {

  // Esta instrucción lee el ultimo valor de un canal publico
  float DatoInF = ThingSpeak.readFloatField(ChannelNumber, Number);
  // Esta instrucción leee el ultimo valor de un canal privado
  //float voltage = ThingSpeak.readFloatField(myChannelNumber, 1, myReadAPIKey);
  Serial.print ("El ultimo valor es: ");
  Serial.println (DatoInF);

  if(DatoInF == 1){
    digitalWrite(salida, LOW);
  }
  else{
    digitalWrite(salida, HIGH);
  }

}
