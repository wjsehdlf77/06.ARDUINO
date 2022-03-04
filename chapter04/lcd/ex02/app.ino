#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    lcd.init();
    lcd.backlight();
    lcd.setCursor(4, 0);
    lcd.print("Su Hyun!");
    lcd.setCursor(2, 1);
    lcd.print("I LOVE YOU!!");
}

void loop()
{
    // put your main code here, to run repeatedly:
int n;
for(n = 0;n < 2;n++){
    lcd.scrollDisplayLeft(); // 왼쪽으로 한 칸씩 이동
        delay(500);
}
    for(n = 0;n < 2;n++){
lcd.scrollDisplayRight(); // 오른쪽으로 한 칸씩 이동
        delay(500);
}
    for(n = 0;n < 2;n++){
lcd.scrollDisplayRight(); // 오른쪽으로 한 칸씩 이동
        delay(500);
}
for(n = 0;n < 2;n++){
    lcd.scrollDisplayLeft(); // 왼쪽으로 한 칸씩 이동
        delay(500);
}

}