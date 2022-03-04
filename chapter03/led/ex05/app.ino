const int led_pin[4] = {9, 7, 5, 3};

const int led_out[6][4] = {
    {1,0,0,0},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1},
    {0,0,1,0},
    {0,1,0,0},
};

int out_no = 0;
void setup() {
    int n;

    for(n = 0; n < 4; n++) {
        pinMode(led_pin[n], OUTPUT);
        digitalWrite(led_pin[n], LOW);
    }
}

void loop() {
    int n;

    for(n = 0; n < 4; n++) {
        digitalWrite(led_pin[n], led_out[out_no][n]);

    }
    out_no++;
    if(out_no == 6) out_no = 0;

    delay(1000);   
}