#include <ESP8266WiFi.h>
#include <MiniCom.h>

const char *ssid = "1309호";
const char *password = "ttolla5405!";
MiniCom com;

void wifi_connect() {
    WiFi.begin(ssid, password);
    com.print(0, "try to connect");
    Serial.println();
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    com.print(0,"WIFI connected");
    com.print(1, WiFi.localIP().toString().c_str());
    Serial.println();
    Serial.println(WiFi.localIP());
}

void setup()
{
	com.init();
    wifi_connect();
}

void loop()
{
	com.run();
}
