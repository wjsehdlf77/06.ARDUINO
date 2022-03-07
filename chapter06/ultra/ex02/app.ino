#include <MiniCom.h>
#include <Ultra.h>

MiniCom com;
Ultra ultra(5, 6);

void check()
{
    int distance = ultra.getDistance();
    com.print(1, "Dist.(cm", distance);
}

void setup()
{
    com.init();
    com.print(0, "[[Distance]]");
    com.setInterval(1000, check);
}

void loop()
{
    com.run();
}