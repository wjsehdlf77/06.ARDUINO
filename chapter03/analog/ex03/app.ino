#include <PWMLed.h>

const int var_pin = A0;
PWMLed led(9);

void setup()
{
    
}

void loop()
{
    int analog_val, pwm_val;
    analog_val = analogRead(var_pin);
    pwm_val = map(analog_val, 0, 1023, 255, 0);

    led.setValue(pwm_val);
}