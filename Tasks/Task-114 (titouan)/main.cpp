#include "mbed.h"

DigitalOut RedLED(PC_2,1);
DigitalOut YellowLED(PC_3,1);
DigitalOut GreenLED(PC_6,1);

// main() runs in its own thread in the OS
int main()
{
    while (true) {
        RedLED = 1;
        wait_us(2000000); // 2 sec

        RedLED = 1;
        YellowLED = 1;
        wait_us(2000000);

        RedLED = 0;
        YellowLED = 0;
        GreenLED = 1;
        wait_us(2000000);

        GreenLED = 0;
        int count = 0;
        while (count < 4) {
            YellowLED = 1;
            wait_us(250000);
            YellowLED = 0;
            wait_us(250000);   
            count = count + 1;   
        }

    }
}

