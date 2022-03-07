# 1 "c:\\workspace\\06.ARDUINO\\chapter06\\ultra\\ex04\\app.ino"
# 2 "c:\\workspace\\06.ARDUINO\\chapter06\\ultra\\ex04\\app.ino" 2
# 3 "c:\\workspace\\06.ARDUINO\\chapter06\\ultra\\ex04\\app.ino" 2


MiniCom com;
Ultra ultra(5, 6);

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
