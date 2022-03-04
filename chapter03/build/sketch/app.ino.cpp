#include <Arduino.h>
#line 1 "c:\\workspace\\06.ARDUINO\\chapter03\\analog\\ex01\\app.ino"
#include <SimpleTimer.h>

const int var_pin = A0;
int analog_val;

SimpleTimer timer;

#line 8 "c:\\workspace\\06.ARDUINO\\chapter03\\analog\\ex01\\app.ino"
void check();
#line 23 "c:\\workspace\\06.ARDUINO\\chapter03\\analog\\ex01\\app.ino"
void setup();
#line 29 "c:\\workspace\\06.ARDUINO\\chapter03\\analog\\ex01\\app.ino"
void loop();
#line 8 "c:\\workspace\\06.ARDUINO\\chapter03\\analog\\ex01\\app.ino"
void check() {
    int digital_val;
    float ff;

    digital_val = analogRead(var_pin);
    ff = (float)digital_val / 1023. * 5.0;

    Serial.print("Input Voltage(0~5V) = ");
    Serial.println(ff);

    Serial.print("Digital Value(0~1023) = ");
    Serial.println(digital_val);
    Serial.println("-------------------------------------------");
}

void setup()
{
    Serial.begin(115200);
    timer.setInterval(2000, check);
}

void loop()
{
    timer.run();
}


