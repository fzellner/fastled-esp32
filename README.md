# fastled-esp32
ESP32 fastLED webserver

This project is taken from [ESP32 FastLED Web Server](https://github.com/jasoncoon/esp32-fastled-webserver) and customized to my own necessities.
Currently working with WS2812b led strip running 300 LEDs

## Important notes:
Set this link on preferences, to install ESP32 board. I'm currently running it, on Wemos LOLIN32
* [ESPRESSIF](https://dl.espressif.com/dl/package_esp32_index.json)

Using arduino IDE, need to add these libraries and tools:
* [FastLED](https://github.com/FastLED/FastLED)
* [ESP32 Arduino Libraries & Tools](https://github.com/espressif/arduino-esp32)
* [ESP8266/ESP32 WebServer](https://github.com/bbx10/WebServer_tng)

* Create a secrets.h file to add your WiFi SSID and password;
* On **wifi.h** file, there is 2 methods that add static ip address and the hostname for the board. The default ip is **192.168.0.200** and the hostname is **ESP32**. Change at your will

## WIP:
* [ ] Alexa support
