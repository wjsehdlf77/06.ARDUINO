#include <Arduino.h>
#line 1 "c:\\workspace\\06.ARDUINO\\chapter05\\rfid\\ex01\\app.ino"
#include <SPI.h>
#include <MFRC522.h>
#include <Buzzer.h>
#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc(SS_PIN, RST_PIN);
Buzzer bizzer(3);

byte myId[] = {49, 181, 185, 26};

#line 12 "c:\\workspace\\06.ARDUINO\\chapter05\\rfid\\ex01\\app.ino"
bool equalId(byte *id1, byte *id2);
#line 21 "c:\\workspace\\06.ARDUINO\\chapter05\\rfid\\ex01\\app.ino"
void setup();
#line 28 "c:\\workspace\\06.ARDUINO\\chapter05\\rfid\\ex01\\app.ino"
void loop();
#line 12 "c:\\workspace\\06.ARDUINO\\chapter05\\rfid\\ex01\\app.ino"
bool equalId(byte *id1, byte *id2) {
    for (int byte = 0; byte < 4; byte++) {
        if (id1[byte] != id2[byte]) {
            return false;
        }
    }
    return true;
}

void setup()
{
    Serial.begin(115200);
    SPI.begin();
    mfrc.PCD_Init();
}

void loop()
{
    if (!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial() ) {
        delay(500);
        return;
    }
    
    if (equalId(myId, mfrc.uid.uidByte)) {
        Serial.println("Equal");
        bizzer.beep(100);
    }
    else {
        bizzer.beep(2000);
    }

    // Serial.print("Card UID :");

    // for(byte i = 0; i < 4; i++) {
    //     Serial.print(mfrc.uid.uidByte[i]);
    //     Serial.print(" ");
    // }

    // Serial.println();
}
