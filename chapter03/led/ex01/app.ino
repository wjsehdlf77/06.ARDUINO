const int pu_led_pin = 3;
const int pd_led_pin = 4;


void setup()
{
    pinMode(pu_led_pin, OUTPUT);
	pinMode(pd_led_pin, OUTPUT);
}

void loop()     //핀의 디폴트 출력은low
{
	digitalWrite(pd_led_pin, HIGH);
    digitalWrite(pu_led_pin, LOW);

}
