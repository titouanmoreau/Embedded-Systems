#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 500 

DigitalOut red(TRAF_RED1_PIN,1);         //Note the initial state
DigitalOut amber(TRAF_YEL1_PIN,0);
DigitalOut green(TRAF_GRN1_PIN,0);

LCD_16X2_DISPLAY lcd;

int main()
{
    while (true)
    {
    red = 1; // red on
    lcd.cls();
    lcd.puts("Red");
    wait_us(10000000); // wait 10 sec 

    amber = 1; // yellow on 
    lcd.cls();
    lcd.puts("Red and Yellow");
    wait_us(2000000); // wait 2 sec
    red = 0; // red off
    amber = 0; // yellow off

    green = 1; //green on
    lcd.cls();
    lcd.puts("Green");    
    wait_us(10000000); // wait 10 sec
    green = 0; // green off

    amber = 1; // yellow on 
    lcd.cls();
    lcd.puts("Yellow");
    wait_us(2000000); // wait 2 sec
    amber = 0; // yellow off
    }

    
}
