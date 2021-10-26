#include "mbed.h"

DigitalIn ButtonA(PG_0); //Button A
DigitalIn ButtonB(PG_1);  //Buton B
DigitalIn ButtonC(PG_2, PinMode::PullDown); //Button C
DigitalIn ButtonD(PG_3, PinMode::PullDown); //Button D

DigitalOut redLED(PC_2); //Red Traffic 1

// main() runs in its own thread in the OS
int main()
{
    int btnA, btnB, btnC, btnD;
    // Turn OFF the red LED
    redLED = 0;

    while (true) {
    
        // Wait for both button to be pressed
        do {
            btnA = ButtonA; //Read button A
            btnB = ButtonB; //read bitton B
            btnC = ButtonC; //Read button c
            btnD = ButtonD; //read bitton D
        } while ((btnA == 0) || (btnB == 0) || (btnC == 0) || (btnD == 0));

        //Toggle the red LED
        redLED = !redLED;

        //Wait for noise to settle
        wait_us(10000);

        // Wait for either button to be released
        do {
            btnA = ButtonA; //Read button A
            btnB = ButtonB; // read button b
            btnC = ButtonC; //Read button c
            btnD = ButtonD; //read bitton D
        } while ((btnA == 1) && (btnB == 1) && (btnC == 0) && (btnD == 0));

        //Wait for noise to settle
        wait_us(10000);
    }
}

