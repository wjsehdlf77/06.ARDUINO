# 1 "c:\\workspace\\06.ARDUINO\\chapter06\\ultra\\ex01\\app.ino"
# 2 "c:\\workspace\\06.ARDUINO\\chapter06\\ultra\\ex01\\app.ino" 2

MiniCom com;

int echoPin = 5;
int triggerPin = 6;


void check()
{
    digitalWrite(triggerPin, 0x1);
    delayMicroseconds(10);
    digitalWrite(triggerPin, 0x0);

    int distance = pulseIn(echoPin, 0x1) / 58;
    com.print(1, "Dist.(cm) = ", distance);
}

void setup()
{
    com.init();
    com.print(0, "[[Distance]]");
    com.setInterval(1000, check);
    pinMode(echoPin, 0x0);
    pinMode(triggerPin, 0x1);
}

void loop()
{
    com.run();
}
