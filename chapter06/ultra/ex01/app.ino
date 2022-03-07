#include <MiniCom.h>

MiniCom com;

int echoPin = 5;
int triggerPin = 6;


void check()
{
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    int distance = pulseIn(echoPin, HIGH) / 58;
    com.print(1, "Dist.(cm) = ", distance);
}

void setup()
{
    com.init();
    com.print(0, "[[Distance]]");
    com.setInterval(1000, check);
    pinMode(echoPin, INPUT);
    pinMode(triggerPin, OUTPUT);
}

void loop()
{
    com.run();
}