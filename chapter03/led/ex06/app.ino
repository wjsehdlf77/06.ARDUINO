#include "Led.h"

Led led1(9); //생성자 호출
Led led2(7);
Led led3(5);
Led led4(3);
void setup()
{
    
}

void loop()
{
    led1.blink(1000);
    led2.blink(900);
    led3.blink(800);
    led4.blink(700);
    
}