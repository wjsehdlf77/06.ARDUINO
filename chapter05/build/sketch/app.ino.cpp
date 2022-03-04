#include <Arduino.h>
#line 1 "c:\\workspace\\06.ARDUINO\\chapter05\\joystick\\ex02\\app.ino"
#include <MiniCom.h>
#include <Analog.h>
#include <Button.h>
#include <Servo.h>

MiniCom com;
Analog x(A2, 180, 0); //서브모터 방향제어
// Analog x(A2, -100, 100);
Analog y(A1,100, -100); //rc카의 속도 빛 방향제어
Button z(A0);
Servo servo;

int servo_pin = 5;

#line 15 "c:\\workspace\\06.ARDUINO\\chapter05\\joystick\\ex02\\app.ino"
void check();
#line 31 "c:\\workspace\\06.ARDUINO\\chapter05\\joystick\\ex02\\app.ino"
void setup();
#line 40 "c:\\workspace\\06.ARDUINO\\chapter05\\joystick\\ex02\\app.ino"
void loop();
#line 15 "c:\\workspace\\06.ARDUINO\\chapter05\\joystick\\ex02\\app.ino"
void check() {
    int dx, dy;
    boolean sw;

    dx = x.read();
    dy = y.read();
    sw = z.read();
    servo.write(dx);

    char buf[17];
    sprintf(buf, "%d, %d [%d]", dx, dy, sw);
    com.print(1, buf);
    

}

void setup()
{
    com.init();
    servo.attach(servo_pin);
    com.setInterval(100, check);
    com.print(0, "[[Joystick]]");

}

void loop()
{
    com.run();
}

