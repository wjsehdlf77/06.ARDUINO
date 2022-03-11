#include <Arduino.h>
#line 1 "c:\\workspace\\06.ARDUINO\\NODEMCU\\nodemcu\\ex06\\app.ino"
#include <MqttCom.h>
#include <DHT.h>
#include <Analog.h>

const char *ssid = "1309호";
const char *password = "ttolla5405!";
const char *mqtt_server = "192.168.0.4";

MqttCom com;
DHT dht11(D6, DHT11); // DHT11 객체 생성
Analog cds(A0,0, 100);

#line 13 "c:\\workspace\\06.ARDUINO\\NODEMCU\\nodemcu\\ex06\\app.ino"
void publish();
#line 27 "c:\\workspace\\06.ARDUINO\\NODEMCU\\nodemcu\\ex06\\app.ino"
void setup();
#line 33 "c:\\workspace\\06.ARDUINO\\NODEMCU\\nodemcu\\ex06\\app.ino"
void loop();
#line 13 "c:\\workspace\\06.ARDUINO\\NODEMCU\\nodemcu\\ex06\\app.ino"
void publish() {
float fh, fc;
fh = dht11.readHumidity(); // 습도 측정
fc = dht11.readTemperature(); // 섭씨 온도 측정
int illu = cds.read(); // 조도 측정
if (isnan(fh) || isnan(fc)) { // 측정 실패시에는 출력없이 리턴
Serial.println("DHT11 read failed!!");
return;
}
com.publish("iot/doyle/livingroom/temp", fc);
com.publish("iot/doyle/livingroom/humi", fh);
com.publish("iot/doyle/livingroom/illu", illu);
}

void setup() {
com.init(ssid, password);
com.setServer(mqtt_server, NULL, NULL);
com.setInterval(2000, publish);
dht11.begin();
}
void loop() {
com.run();
}
