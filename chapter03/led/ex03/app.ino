const int led1_pin = 9;
const int led2_pin = 7;
const int led3_pin = 5;
const int led4_pin = 3;



void setup()
{
 pinMode(led1_pin, OUTPUT);
 pinMode(led2_pin, OUTPUT);
 pinMode(led3_pin, OUTPUT);
 pinMode(led4_pin, OUTPUT);
}

void loop()
{
    digitalWrite(led1_pin, HIGH);
    digitalWrite(led2_pin, LOW);
    digitalWrite(led3_pin, LOW);
    digitalWrite(led4_pin, LOW);
    delay(300);

    digitalWrite(led1_pin, LOW);
    digitalWrite(led2_pin, HIGH);
    digitalWrite(led3_pin, LOW);
    digitalWrite(led4_pin, LOW);
    delay(300);

    digitalWrite(led1_pin, LOW);
    digitalWrite(led2_pin, LOW);
    digitalWrite(led3_pin, HIGH);
    digitalWrite(led4_pin, LOW);
    delay(300);

    digitalWrite(led1_pin, LOW);
    digitalWrite(led2_pin, LOW);
    digitalWrite(led3_pin, LOW);
    digitalWrite(led4_pin, HIGH);

    delay(300);
}