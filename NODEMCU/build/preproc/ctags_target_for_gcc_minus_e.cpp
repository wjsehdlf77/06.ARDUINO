# 1 "c:\\workspace\\06.ARDUINO\\NODEMCU\\nodemcu\\ex03\\app.ino"
# 2 "c:\\workspace\\06.ARDUINO\\NODEMCU\\nodemcu\\ex03\\app.ino" 2

const char *ssid = "1309호";
const char *password = "ttolla5405!";

WifiMiniCom com;
WiFiServer server(80);

void setup()
{
    com.init(ssid, password);
    server.begin();
}

void loop()
{
    WiFiClient client = server.available();
    if (!client) {
        return;
    }

    Serial.println("new clinet");
    while (!client.available()) {
        delay(1);
    }
    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.print("HELLO WORLD!");
    client.println("</html>");
    delay(1);
    Serial.println("Client disonnected");
    Serial.println("");
}
