#include <BtMiniCom.h>
#include <Car.h>


void receive_msg(String msg);

BtMiniCom com(13, 12, receive_msg);
Car car(9, 8 ,7, 3, 5, 4);

void receive_msg(String msg) 
{
    if (msg = "F") {
        car.forward();
    }
    else if (msg = "B") {
        car.backward();
    }
    else if (msg = "L") {
        car.turn_left();
    }
    else if (msg = "R") {
        car.turn_right();
    }
    else if (msg = "S") {
        car.stop();
    }
}
}


void setup() 
{
    com.init();
    car.stop();

}
    void loop() 
{
    com.run();
}