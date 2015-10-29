/*
 Possible commands created in this shetch:

 * "/arduino/digital/13"     -> digitalRead(13)
 * "/arduino/digital/13/1"   -> digitalWrite(13, HIGH)
 * "/arduino/analog/2/123"   -> analogWrite(2, 123)
 * "/arduino/analog/2"       -> analogRead(2)
 * "/arduino/mode/13/input"  -> pinMode(13, INPUT)
 * "/arduino/mode/13/output" -> pinMode(13, OUTPUT)
 * "/arduino/clear" -> sets ALL leds off
 * "/arduino/red" -> sets LEDS up to virtual end red
 * "/arduino/green" -> sets LEDS up to virtual end green
 * "/arduino/blue" -> sets LEDS up to virtual end blue
 * "/arduino/wipe" -> wipes LEDS up to virtual green
 * 
 * //todo
 * "/arduino/wipe/r/g/b/time" -> wipes LEDS up to virtual

 */
#include <Adafruit_NeoPixel.h>
#include "NeoPixel.h"

#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
#include "Bridge.h"


void setup() {
  NPSetup();
  BSetup();
}

void loop() {
  // Get clients coming from server
  YunClient client = server.accept();

  // There is a new client?
  if (client) {
    // Process request
    process(client);

    // Close connection and free resources.
    client.stop();
  }
  
  delay(50); // Poll every 50ms
}

void process(YunClient client) {
  // read the command
  String command = client.readStringUntil('/');

  // is "digital" command?
  if (command == "digital") {
    digitalCommand(client);
  }

  // is "analog" command?
  if (command == "analog") {
    analogCommand(client);
  }

  // is "mode" command?
  if (command == "mode") {
    modeCommand(client);
  }

  if (command == "wipe") {
   wipeCommand();
  }

  if (command == "clear") {
   clear();
  }

  if (command == "red") {
   red();
  }

  if (command == "green") {
   green();
  }

  if (command == "blue") {
   blue();
  }
}
