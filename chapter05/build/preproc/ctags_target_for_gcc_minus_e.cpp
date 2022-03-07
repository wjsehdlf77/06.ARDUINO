# 1 "c:\\workspace\\06.ARDUINO\\chapter05\\tilt\\ex01\\app.ino"
# 2 "c:\\workspace\\06.ARDUINO\\chapter05\\tilt\\ex01\\app.ino" 2

Led led(9);

const int tilt_pin = 4;

void setup()
{
    pinMode(tilt_pin, 0x0);
}

void loop()
{
    bool t_sw;

    t_sw = digitalRead(tilt_pin);
    led.setValue(t_sw);
}
