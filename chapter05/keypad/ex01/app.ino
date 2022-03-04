#include <MiniCom.h>
#include <Keypad.h>

MiniCom com;

const byte ROWS = 4; // 행(rows) 개수
const byte COLS = 4; // 열(columns) 개수

char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte rowPins[ROWS] = {7, 6, 5, 4}; 
byte colPins[COLS] = {8, 9, 10, 11}; 




Keypad keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String input = "";
bool b_input = false;

void setup()
{
	com.init();
    com.print(0,"[[Keypad Test]]");
}

void loop()
{
	char key = keypad.getKey();
    if (key == '*') {
        b_input = true;
        input = "";

        // com.print(a, str.c_str());
        
    }
    else if (key == '#') {
        b_input = false;
        Serial.print("입력완료 : ");
        Serial.println(input);
    }
    else if (key && b_input) {
        input += key;
        com.print(1, input.c_str());
    }
}
