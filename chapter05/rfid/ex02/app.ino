#include <EEPROM.h>



byte myId[] = {49, 181, 185, 26};

void setup()
{
    Serial.begin(115200);
    for (int i  = 0; i < 4; i++)
    {
        //myId를 eeprom에 저장
        EEPROM.write(i, myId[i]);
    }
}

void loop()
{
    byte savedId[4];
    //myId를 eeprom에서 일기
    for (int i  = 0; i < 4; i++)
    {
        //myId를 eeprom에 저장
        savedId[i] = EEPROM.read(i);
        Serial.print(savedId[i]);
        Serial.print(' ');
    }
    Serial.println();
    delay(5000);
}