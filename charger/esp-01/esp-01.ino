// code mostly from https://techtutorialsx.com/2016/07/21/esp8266-post-requests/

// GPIO out sourced here
// https://simple-circuit.com/arduino-esp-01-esp8266-programming/

// web server code from here
// https://tttapa.github.io/ESP8266/Chap10%20-%20Simple%20Web%20Server.html
// https://techtutorialsx.com/2017/03/26/esp8266-webserver-accessing-the-body-of-a-http-request/

#define BLUE_LED 1 // blue LED as WiFi status, cannot be used with Serial.print... calls same tx pin
#define CHARGER_TRIGGER 3 // use RX for low boot

#include "env.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

int sleepDelay = 1000; // 86.4e3 full day in seconds

void blueLedOn()
{
  digitalWrite(BLUE_LED, LOW); // reversed LOW = ON
}

void blueLedOff()
{
  digitalWrite(BLUE_LED, HIGH);
}

void startCharging()
{
  digitalWrite(CHARGER_TRIGGER, LOW);
}

void stopCharging()
{
  digitalWrite(CHARGER_TRIGGER, HIGH);
}

void connectToWiFi()
{
  WiFi.begin(wiFiSsid, wiFiPass);
  int connectionAttempts = 0;

  while (WiFi.status() != WL_CONNECTED and connectionAttempts < 20)
  {
    delay(250);
    connectionAttempts += 1;
  }

  blueLedOn();
}

void handlePost()
{
  if (server.hasArg("start_charging"))
  {
    startCharging();
  }

  if (server.hasArg("stop_charging"))
  {
    stopCharging();
  }

  server.send(200, "OK");
}

void setup()
{
  // Serial.begin(115200); // can't use this since using rx pin

  // can't use with Serial calls, serial calls won't show up
  pinMode(BLUE_LED, OUTPUT);
  pinMode(CHARGER_TRIGGER, OUTPUT);
  stopCharging(); // set RX to low

  connectToWiFi();

  server.on("/", HTTP_POST, handlePost);
  server.begin();
}

void loop()
{
  server.handleClient();

  if (WiFi.status() != WL_CONNECTED)
  {
    blueLedOff();
    connectToWiFi();
  }
}
