#include <MiniCom.h>

MiniCom com;

void check()
{

}

void setup()
{
    com.init();
    com.print(0, "[[MiniCom]]");
    com.setInterval(1000, check);
}

void loop()
{
    com.run();
}

