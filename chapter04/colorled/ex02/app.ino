// 1초 간격으로 색상을 랜덤하게 변경. -->무드등!
//버튼을 누르면 색상 변경 시간을 변경 0.5초 -> 1초 -> 2초
#include <ColorLed.h>
#include <SimpleTimer.h>
#include <Button.h>


SimpleTimer timer;

ColorLed leds(9, 10, 11);
Button btn(2);

const int COLOR_NUM = 10;
int colors[COLOR_NUM][3] = {
    {255, 0, 0},
    {23, 30, 40},
    {100, 200, 0},
    {30, 70, 120},
    {90, 50, 200},
    {255, 255, 255},
    {100, 200, 0},
    {70, 170, 30},
    {0, 0, 255},
    {0, 0, 0}
};

int color_index = -1; //현재 배열의 인덱스

int INTERVAL_NUM = 3;
int INTERVALS[] = {500, 1000, 2000};
int interval_index = 0;
int timer_id = -1; //현재 가동 중인  Timer의 ID

void check()
{   
    color_index = (color_index + 1) % COLOR_NUM;
    // leds.rgb(colors[color_index][0], colors[color_index][1], colors[color_index][2]);

    int *pcolor = colors[color_index];
    leds.rgb(pcolor[0], pcolor[1], pcolor[2]);
    //leds.random();
}

void change_interval()
{
    //1. 기존 타이머 제거
    //2. interval_index조정
    //3. 타이머 재설정
    timer.deleteTimer(timer_id);
    interval_index = (interval_index + 1) % INTERVAL_NUM;
    timer_id = timer.setInterval(INTERVALS[interval_index], check);


}

void setup()
{
    Serial.begin(115200);
    timer_id = timer.setInterval(INTERVALS[0], check);
    btn.setCallback(change_interval);

}

void loop()
{
    btn.check();
    timer.run();
    
}