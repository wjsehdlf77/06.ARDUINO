#include <SPI.h>
#include <MFRC522.h>
#include <Buzzer.h>
#include <Servo.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc(SS_PIN, RST_PIN);
Buzzer bizzer(3);

byte myId[] = {49, 181, 185, 26};

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

//수행평가 여기까지 servo모터까지 만든거를 클래스로 정의 RFID Reader
//