#include <DNSServer.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include "ESPAsyncWebServer.h"

#define magnetPin 21
#define ledPin 2

DNSServer dnsServer;
AsyncWebServer server(80);

byte magnetConnected;
int seconds = 0;
int maxSeconds = 10;

void secondsInc()
{
  seconds ++;
  Serial.println(seconds);
  delay(1000);
}

void setup()
{
  Serial.begin(9600);
  pinMode(magnetPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  //DNS stuff

  //And now my stuff
  magnetConnected = digitalRead(magnetPin);

  if (magnetConnected == HIGH)
  {
    if (seconds < maxSeconds)
    {
      secondsInc();

      if (seconds == maxSeconds)
      {
        digitalWrite(ledPin, HIGH);
      }
    }
  }
  else
  {
    seconds = 0;
    digitalWrite(ledPin, LOW);
  }
}