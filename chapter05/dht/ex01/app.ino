#include <MiniCom.h>
#include <DHT.h>

DHT dht11(10, DHT11);
MiniCom com;

void check()
{
    float fh, fc, ff;

    fh = dht11.readHumidity();          //습도
    fc = dht11.readTemperature();       //섭씨 온도
    ff = dht11.readTemperature(true);   //화씨

    if (isnan(fh) || isnan(fc) || isnan(ff)) {
        com.print(1, "Failed");
        return;
    }
    com.print(1, "T :", fc, "H", fh);
}

void setup()
{
    com.init();
    dht11.begin();
    com.print(0, "[[DHT11]]");
    com.print(1, "Preoaring DHT11");
    com.setInterval(2000, check);
}

void loop()
{
    com.run();
}