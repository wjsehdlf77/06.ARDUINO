#include <Arduino.h>
#line 1 "c:\\workspace\\06.ARDUINO\\chapter06\\ultra\\ex01\\app.ino"
#include <MiniCom.h>

MiniCom com;

int echoPin = 5;
int triggerPin = 6;


#line 9 "c:\\workspace\\06.ARDUINO\\chapter06\\ultra\\ex01\\app.ino"
void check();
#line 19 "c:\\workspace\\06.ARDUINO\\chapter06\\ultra\\ex01\\app.ino"
void setup();
#line 28 "c:\\workspace\\06.ARDUINO\\chapter06\\ultra\\ex01\\app.ino"
void loop();
#line 9 "c:\\workspace\\06.ARDUINO\\chapter06\\ultra\\ex01\\app.ino"
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
