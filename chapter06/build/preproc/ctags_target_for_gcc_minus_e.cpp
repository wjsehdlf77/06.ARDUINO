# 1 "c:\\workspace\\06.ARDUINO\\chapter06\\pir\\ex02\\app.ino"
# 2 "c:\\workspace\\06.ARDUINO\\chapter06\\pir\\ex02\\app.ino" 2
# 3 "c:\\workspace\\06.ARDUINO\\chapter06\\pir\\ex02\\app.ino" 2
# 4 "c:\\workspace\\06.ARDUINO\\chapter06\\pir\\ex02\\app.ino" 2

MiniCom com;
Led led(8);
Pir pir(7);

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
