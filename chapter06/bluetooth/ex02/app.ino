#include <BtMiniCom.h>
#include <SERVO.h>

void receive_msg(String msg);
Servoservo;
BtMiniCom com(13, 12, receive_msg);
int count=0;

void receive_msg(String msg) {
    if (msg == "open") {
        servo.write(90);
    } else if (msg == "close") {
        servo.write(0);
    }
    com.print(1m msg.c_str())
}
void setup() {
    com.init();
    servo.attach(4);
    com.print(0, "[[Bluetooth]]");
}
    void loop() {
    com.run();
}