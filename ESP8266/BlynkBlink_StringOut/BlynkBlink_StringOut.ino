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
//#include <SimpleTimer.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "16017c88da5f4510bcc7e5a43df7460d";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Ethan's iPhone";
char pass[] = "1212qwas";

char serialinput[10];
//float t = float(random(100, 300)) / 10;
// Format: 1 decimal place, add ℃
//String str = String(t, 1) + "℃";
//String strout = String(serialinput[]);

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

  // if you type "Marco" into Terminal Widget - it will respond: "Polo:"
  /*if (String("Marco") == param.asStr()) {
    terminal.println("You said: 'Marco'") ;
    terminal.println("I said: 'Polo'") ;
  } else {

    // Send it back
    terminal.print("You said:");
    terminal.write(param.getBuffer(), param.getLength());
    terminal.println();
  }*/
  
  // Ensure everything is sent
  terminal.flush();
}


void loop()
{
  Blynk.run();
  
  //Blynk.virtualWrite(V0,"ID  Length");
  //Blynk.virtualWrite(V1,"D0  D1  D2  D3  D4  D5  D6  D7");
  //t = float(random(100, 300)) / 10;
  //str = String(t, 1) + "℃";
  
  if (Serial.available() > 0) 
  {
      //Serial.readBytes(serialinput[0],32);
      //strout=Serial.readString();
      
      terminal.write(Serial.read());
      //terminal.println();
  }
}

