#include <Led.h>

Led led(9);

const int tilt_pin = 4;

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