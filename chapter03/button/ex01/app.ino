#include <Led.h>

const int pu_sw_pin = 10;
Led led1(8);

const int pd_sw_pin = 4;
Led led2(2);



void setup()
{
    pinMode(pu_sw_pin, INPUT);
    pinMode(pd_sw_pin, INPUT);
}

void loop()
{
    boolean pu_sw, pd_sw; 

    pu_sw = digitalRead(pu_sw_pin);
    led1.setValue(pu_sw);

    pd_sw = digitalRead(pd_sw_pin);
    led2.setValue(pd_sw);
}