# 1 "c:\\workspace\\06.ARDUINO\\chapter06\\dcmotor\\ex01\\app.ino"
# 2 "c:\\workspace\\06.ARDUINO\\chapter06\\dcmotor\\ex01\\app.ino" 2

// int ENAPin = 9;
// int in1Pin = 8;
// int in2Pin = 7;

// int ENBPin = 3;
// int in3Pin = 5;
// int in4Pin = 4;

Car car(9, 8 ,7, 3, 5, 4);

void setup()
{
    car.stop();
}

void loop()
{
    car.forward();

    delay(1000);

    car.backward();

    delay(1000);

    car.turn_left();

    delay(1000);

    car.turn_right();

    delay(1000);

    car.stop();

    delay(5000);


}
