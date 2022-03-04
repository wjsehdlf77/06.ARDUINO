#include <MiniCom.h>
#include <Analog.h>
#include <Button.h>
#include <Servo.h>

MiniCom com;
Analog x(A2, 0, 180); //서브모터 방향제어
Analog y(A1,100, -100); //rc카의 속도 빛 방향제어
Button z(A0);

void check() {
    int dx, dy;
    boolean sw;

    dx = x.read();
    dy = y.read();
    sw = z.read();

    char buf[17];
    sprintf(buf, "%d, %d [%d]", dx, dy, sw);
    com.print(1, buf);
}

void setup()
{
    com.init();
    com.setInterval(100, check);
    com.print(0, "[[Joystick]]");
}

void loop()
{
    com.run();
}

