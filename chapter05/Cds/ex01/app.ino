#include <MiniCom.h>
#include <Analog.h>
#include <Led.h>

Led led(8);
MiniCom com;
Analog cds(A0, 0, 100);


void check()
{
    int value = cds.read();
    led.setValue(value > 50);
    com.print(1,"Illu : ", value);
}

void setup()
{
    com.init();
    com.print(0, "[[CDS TEST]]");
    com.setInterval(100, check);
}

void loop()
{
    com.run();
}