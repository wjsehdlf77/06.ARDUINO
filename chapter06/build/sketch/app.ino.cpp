#include <Arduino.h>
#line 1 "c:\\workspace\\06.ARDUINO\\chapter06\\pir\\ex02\\app.ino"
#include <MiniCom.h>
#include <Led.h>
#include <Pir.h>

MiniCom com;
Led led(8);
Pir pir(7);

#line 9 "c:\\workspace\\06.ARDUINO\\chapter06\\pir\\ex02\\app.ino"
void detect_on();
#line 14 "c:\\workspace\\06.ARDUINO\\chapter06\\pir\\ex02\\app.ino"
void detect_off();
#line 18 "c:\\workspace\\06.ARDUINO\\chapter06\\pir\\ex02\\app.ino"
void setup();
#line 25 "c:\\workspace\\06.ARDUINO\\chapter06\\pir\\ex02\\app.ino"
void loop();
#line 9 "c:\\workspace\\06.ARDUINO\\chapter06\\pir\\ex02\\app.ino"
void detect_on() {
    com.print(1, "Motion detected!");
    led.on();
}

void detect_off() {
    com.print(1, "Motion ended!");
    led.off();
}
void setup()
{
    com.init();
    com.print(0, "[[Motion]]");
    pir.setCallback(detect_on, detect_off);
}

void loop()
{
    com.run();
    pir.check();
}
