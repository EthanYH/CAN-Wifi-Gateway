/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * This example runs directly on ESP8266 chip.
 *
 * You need to install this for ESP8266 development:
 *   https://github.com/esp8266/Arduino
 *
 * Please be sure to select the right ESP8266 module
 * in the Tools -> Board menu!
 *
 * Change WiFi ssid, pass, and Blynk auth token to run :)
 *
 **************************************************************/

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "token";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ssid";
char pass[] = "pass";

char serialinput[10];

WidgetTerminal terminal(V4);

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);  

  // This will print Blynk Software version to the Terminal Widget when
  // your hardware gets connected to Blynk Server
  terminal.println(F("Blynk v" BLYNK_VERSION ": Device started"));
  terminal.println("-------------");
  terminal.println("Type 'Marco' and get a reply, or type");
  terminal.println("anything else and get it printed back.");
  terminal.flush();
}

// You can send commands from Terminal to your hardware. Just use
// the same Virtual Pin as your Terminal Widget
BLYNK_WRITE(V4)
{
  // Ensure everything is sent
  terminal.flush();
}


void loop()
{
  Blynk.run();
  
  if (Serial.available() > 0) 
  {
      terminal.write(Serial.read());
  }
}

