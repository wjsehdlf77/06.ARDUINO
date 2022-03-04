//1초에 10번 가변 저항을 읽어서
//가변 저항의 값을 lcd로 출력하세요

#include <SimpleTimer.h>
#include <Analog.h>
#include <LiquidCrystal_I2C.h>


SimpleTimer timer;
Analog sensor(A0, 1023, 0);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void check()
{
    
    int value = sensor.read();
    Serial.println(value);
    //lcd.clear();
    lcd.setCursor(0, 1);

    char str[17];
    sprintf(str, "value : %4d", value);
    lcd.print(str);
}

void setup()
{
    Serial.begin(115200);
    lcd.init();
    lcd.backlight();
    timer.setInterval(100, check);
    lcd.print("[reg. value]");
    lcd.setCursor(0, 0);
}

void loop()
{
    timer.run();
}