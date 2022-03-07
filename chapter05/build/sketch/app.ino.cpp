#include <Arduino.h>
#line 1 "c:\\workspace\\06.ARDUINO\\chapter05\\tilt\\ex01\\app.ino"
#include <Led.h>

Led led(9);

const int tilt_pin = 4;

#line 7 "c:\\workspace\\06.ARDUINO\\chapter05\\tilt\\ex01\\app.ino"
void setup();
#line 12 "c:\\workspace\\06.ARDUINO\\chapter05\\tilt\\ex01\\app.ino"
void loop();
#line 7 "c:\\workspace\\06.ARDUINO\\chapter05\\tilt\\ex01\\app.ino"
void setup()
{
    pinMode(tilt_pin, INPUT);
}

void loop()
{
    bool t_sw;

    t_sw = digitalRead(tilt_pin);
    led.setValue(t_sw);
}
