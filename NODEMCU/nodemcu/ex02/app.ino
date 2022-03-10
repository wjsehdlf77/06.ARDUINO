#include <WifiMiniCom.h>

const char *ssid = "1309호";
const char *password = "ttolla5405!";
WifiMiniCom com;

void setup()
{
    com.init(ssid, password);
}

void loop()
{
    com.run();
}