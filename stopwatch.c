#include <at89c5131.h>
#include "lcd.h"
int count = 0;
int time = 0;
int seconds = 0;
int minutes = 0;
int seconds_ones = 0;
int seconds_tens = 0;
int minutes_ones = 0;
int minutes_tens = 0;
unsigned char input[5] = "     ";

void timer0_isr () interrupt 1
{
    count++;
    TL0 = 0xC4;
    TH0 = 0xFF;
}

void display(){
    seconds_ones = seconds%10;
    seconds_tens = seconds/10;
    minutes_ones = minutes%10;
    minutes_tens = minutes/10;
    input[4] = '0' + seconds_ones;
    input[3] = '0' + seconds_tens;
    input[2] = ':';
    input[1] = '0' + minutes_ones;
    input[0] = '0' + minutes_tens;
    lcd_cmd(0x80);
    msdelay(4);
    lcd_write_string(input);
}

void main(){
    EA = 1;
	  ET0 = 1;
    TMOD = 0x05;
    count = 0;
    TL0 = 0xC4;
    TH0 = 0xFF;
    lcd_init();
    while(1){
        if (P1_0 == 0){
            TR0 = 0;
        }
        else{
            TR0 = 1;
            seconds = count%60;
            minutes = count/60;
            display();
        }
    }
}   