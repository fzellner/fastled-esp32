/*
   ESP32 FastLED WebServer: https://github.com/jasoncoon/esp32-fastled-webserver
   Copyright (C) 2017 Jason Coon

   Built upon the amazing FastLED work of Daniel Garcia and Mark Kriegsman:
   https://github.com/FastLED/FastLED

   ESP32 support provided by the hard work of Sam Guyer:
   https://github.com/samguyer/FastLED

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


/*
First of all create a file called secrets.h
and add these variables
const char* ssid = "YOUR_SSID";
const char* password = "PASSWORD";
*/

//Set the hostname for your currently device. (optional)
#define HOSTNAME "ESP32" ///< Hostname. The setup function adds the Chip ID at the end.

const bool apMode = false;

// AP mode password
const char WiFiAPPSK[] = "";

void setupWifi() {
  // Set Hostname.

  setStaticIpAddress()
  setHostName()

  // This part of code will try create static IP address
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }

  // Print hostname.
  Serial.println("Hostname: " + hostname);

  if (apMode)
  {
    WiFi.mode(WIFI_AP);
    WiFi.softAP(hostnameChar, WiFiAPPSK);
    Serial.printf("Connect to Wi-Fi access point: %s\n", hostnameChar);
    Serial.println("and open http://192.168.1.200 in your browser");
  }
  else
  {
    WiFi.mode(WIFI_STA);
    Serial.printf("Connecting to %s\n", ssid);
    if (String(WiFi.SSID()) != String(ssid)) {
      WiFi.begin(ssid, password);
    }
  }
}

void setStaticIpAddress() {
  /*
    // it wil set the static IP address to 192, 168, 1, 200
    IPAddress local_IP(192, 168, 0, 200);
    //it wil set the gateway static IP address to 192, 168, 0,1
    IPAddress gateway(192, 168, 0, 1);
    // Following three settings are optional
    IPAddress subnet(255, 255, 0, 0);
    IPAddress primaryDNS(8, 8, 8, 8);
    IPAddress secondaryDNS(8, 8, 4, 4);
  */
}

void setHostName() {
  String hostname(HOSTNAME);
  uint64_t chipid = ESP.getEfuseMac();
  uint16_t long1 = (unsigned long)((chipid & 0xFFFF0000) >> 16 );
  uint16_t long2 = (unsigned long)((chipid & 0x0000FFFF));
  String hex = String(long1, HEX) + String(long2, HEX); // six octets
  hostname += hex;

  char hostnameChar[hostname.length() + 1];
  memset(hostnameChar, 0, hostname.length() + 1);

  for (uint8_t i = 0; i < hostname.length(); i++)
    hostnameChar[i] = hostname.charAt(i);

  WiFi.setHostname(hostnameChar);
}
