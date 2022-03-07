# 1 "c:\\workspace\\06.ARDUINO\\chapter05\\rfid\\ex01\\app.ino"
# 2 "c:\\workspace\\06.ARDUINO\\chapter05\\rfid\\ex01\\app.ino" 2
# 3 "c:\\workspace\\06.ARDUINO\\chapter05\\rfid\\ex01\\app.ino" 2
# 4 "c:\\workspace\\06.ARDUINO\\chapter05\\rfid\\ex01\\app.ino" 2



MFRC522 mfrc(10, 9);
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
