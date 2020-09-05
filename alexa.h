#include <Espalexa.h>
#include <EspalexaDevice.h>

Espalexa espalexa;


#define STRIP_1 "strip one"

void initAlexa()
{

    server.on("/", HTTP_GET, [](){
    server.send(200, "text/plain", "This is an example index page your server may send.");
    });
    server.on("/test", HTTP_GET, [](){
    server.send(200, "text/plain", "This is a second subpage you may have.");
    });
    server.onNotFound([](){
      if (!espalexa.handleAlexaApiCall(server.uri(),server.arg(0))) //if you don't know the URI, ask espalexa whether it is an Alexa control request
      {
        //whatever you want to do with 404s
        server.send(404, "text/plain", "Not found");
      }
    });

    // Define your devices here.
    espalexa.addDevice(STRIP_1, stripLightChanged); //simplest definition, default state off

    espalexa.begin(&server); //give espalexa a pointer to your server object so it can use your server instead of creating its own
    //server.begin(); //omit this since it will be done by espalexa.begin(&server)
}

void stripLightChanged(uint8_t brightness) {
    Serial.print("Device 1 changed to ");
    
    //do what you need to do here

    //EXAMPLE
    if (brightness == 255) {
      Serial.println("ON");
    }
    else if (brightness == 0) {
      Serial.println("OFF");
    }
    else {
      Serial.print("DIM "); Serial.println(brightness);
    }
}
