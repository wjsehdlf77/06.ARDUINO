#include <SimpleTimer.h>

SimpleTimer timer;

void repeatMe() {
    Serial.print("Uptime (s) :");
    Serial.println(millis() / 1000);
}

void setup()
{
    Serial.begin(115200);
    timer.setInterval(1000, repeatMe);
}

void loop()
{
    timer.run();
}