#include <Arduino.h>
#line 1 "c:\\workspace\\06.ARDUINO\\chapter06\\ultra\\ex04\\app.ino"
#include <MiniCom.h>
#include <Ultra.h>


MiniCom com;
Ultra ultra(5, 6);

#line 8 "c:\\workspace\\06.ARDUINO\\chapter06\\ultra\\ex04\\app.ino"
void notice_in();
#line 13 "c:\\workspace\\06.ARDUINO\\chapter06\\ultra\\ex04\\app.ino"
void notice_out();
#line 17 "c:\\workspace\\06.ARDUINO\\chapter06\\ultra\\ex04\\app.ino"
void setup();
#line 24 "c:\\workspace\\06.ARDUINO\\chapter06\\ultra\\ex04\\app.ino"
void loop();
#line 8 "c:\\workspace\\06.ARDUINO\\chapter06\\ultra\\ex04\\app.ino"
void notice_in()
{
    com.print(1, "NOTICE IN");
}

void notice_out() {
    com.print(1, "NOTICE OUT");
}

void setup()
{
    com.init();
    com.print(0, "[[Distance]]");
    ultra.setThreshold(40, notice_in, notice_out);
}

void loop()
{
    com.run();
    ultra.run();
}
