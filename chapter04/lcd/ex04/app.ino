#include <LiquidCrystal_I2C.h>

uint8_t name_su[8] = {  0x04,
  0x0A,
  0x11,
  0x00,
  0x1F,
  0x04,
  0x04,
  0x04};

uint8_t name_hyun[8] = {  0x01,
  0x09,
  0x1F,
  0x09,
  0x17,
  0x09,
  0x04,
  0x07};

uint8_t name_u[8] = {  0x00,
  0x0A,
  0x1F,
  0x0E,
  0x04,
  0x00,
  0x00,
  0x00};
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
// put your setup code here, to run once:
lcd.init();
lcd.backlight();
lcd.createChar(0, name_su); // '신' 패턴 코드 0으로 저장
lcd.createChar(1, name_hyun); // '동' 패턴 코드 1으로 저장
lcd.createChar(2, name_u); // '욱' 패턴 코드 2으로 저장
}

void loop()
{

lcd.setCursor(6, 0);
lcd.write(0);
lcd.write(1);
lcd.write(2);
}