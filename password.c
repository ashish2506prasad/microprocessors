#include <at89c5131.h>
#include "header_file.h"

code unsigned char display_msg1[]="ENTER PASSWORD  ";	
code unsigned char display_msg2[]="CORRECT PASSWORD";	
code unsigned char display_msg3[]="ACCESS GRANTED  ";	
code unsigned char display_msg4[]="WRONG PASSWORD  ";	
code unsigned char display_msg5[]="ACCESS DENIED   ";	
unsigned char password1[]="15A8*D6#        ";	
unsigned char lsb;
unsigned char input_password[16] = "                ";
unsigned char i,a;

void main()
{
lcd_init();
lcd_cmd(0x80);	//////////Move cursor to first line
msdelay(4);
lcd_write_string(display_msg1);
	
for(i = 0; i<8; i++){
//lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
//lcd_write_string(debug1);	
	while(1){
		P3 = 0x0F;
		msdelay(1);
		lsb = P3 & 0x0F;
		if (lsb == 0x0F)
			break;
	}
	
	//lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
	//lcd_write_string(debug2);
	
	//while(1){
		
		while (1){
			P3 = 0x0F;
			msdelay(1);
			lsb = P3 & 0x0F;
			if(lsb != 0x0F)
				break;
		}
		//lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
		//lcd_write_string(debug3);
		if (lsb != 0x0F){
			msdelay(20);
			P3 = 0x0F;
			msdelay(1);
			lsb = P3 & 0x0F;
			if (lsb == 0x0F){			
				i--;
				break;
			}
			switch(lsb){
				case (0x07):  //col 1
					P3 = 0xEF;
					msdelay(1);
					lsb = P3 & 0x0F;
					if (lsb == 0x07){
						input_password[i]= '1';
						lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
						lcd_write_string(input_password);
					}
					P3 = 0xDF;
					msdelay(1);
					lsb = P3 & 0x0F;
					if (lsb == 0x07){
						input_password[i]= '2';
						lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
						lcd_write_string(input_password);
					}
					P3 = 0xBF;
					msdelay(1);
					lsb = P3 & 0x0F;
					if (lsb == 0x07){
						input_password[i]= '3';
						lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
						lcd_write_string(input_password);
					}			
					P3 = 0x7F;
					msdelay(1);
					lsb = P3 & 0x0F;
					if (lsb == 0x07){
						input_password[i]= 'A';
						lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
						lcd_write_string(input_password);
					}
					
				case (0x0B):  //col 2
					P3 = 0xEF;
					msdelay(1);
					lsb = P3 & 0x0F;
					if (lsb == 0x0B){
						input_password[i]= '4';
						lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
						lcd_write_string(input_password);
					}
					P3 = 0xDF;
					msdelay(1);
					lsb = P3 & 0x0F;
					if (lsb == 0x0B){
						input_password[i]= '5';
						lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
						lcd_write_string(input_password);
					}
					P3 = 0xBF;
					msdelay(1);
					lsb = P3 & 0x0F;
					if (lsb == 0x0B){
						input_password[i]= '6';
						lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
						lcd_write_string(input_password);
					}			
					P3 = 0x7F;
					msdelay(1);
					lsb = P3 & 0x0F;
					if (lsb == 0x0B){
						input_password[i]= 'B';
						lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
						lcd_write_string(input_password);
					}
				
				case (0x0D):  //col 3
					P3 = 0xEF;
					msdelay(1);
					lsb = P3 & 0x0F;
					if (lsb == 0x0D){
						input_password[i]= '7';
						lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
						lcd_write_string(input_password);
					}
					P3 = 0xDF;
					msdelay(1);
					lsb = P3 & 0x0F;
					if (lsb == 0x0D){
						input_password[i]= '8';
						lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
						lcd_write_string(input_password);
					}
					P3 = 0xBF;
					msdelay(1);
					lsb = P3 & 0x0F;
					if (lsb == 0x0D){
						input_password[i]= '9';
						lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
						lcd_write_string(input_password);
					}			
					P3 = 0x7F;
					msdelay(1);
					lsb = P3 & 0x0F;
					if (lsb == 0x0D){
						input_password[i]= 'C';
						lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
						lcd_write_string(input_password);
					}
					
				case (0x0E):  //col 4
					P3 = 0xEF;
					msdelay(1);
					lsb = P3 & 0x0F;
					if (lsb == 0x0E){
						input_password[i]= '*';
						lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
						lcd_write_string(input_password);
					}
					P3 = 0xDF;
					msdelay(1);
					lsb = P3 & 0x0F;
					if (lsb == 0x0E){
						input_password[i]= '0';
						lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
						lcd_write_string(input_password);
					}
					P3 = 0xBF;
					msdelay(1);
					lsb = P3 & 0x0F;
					if (lsb == 0x0E){
						input_password[i]= '#';
						lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
						lcd_write_string(input_password);
					}			
					P3 = 0x7F;
					msdelay(1);
					lsb = P3 & 0x0F;
					if (lsb == 0x0E){
						input_password[i]= 'D';
						lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
						lcd_write_string(input_password);
					}
				
				default:
					lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
					lcd_write_string(input_password);
					break;
						
				}  //switch	
			}    //if
		      //while
}          //for
a=0;
for (i=0;i<8;i++){
	if(input_password[i]==password1[i])
		a=1;
	else{
		a=0;		
		break;
	}
}
	msdelay(500);
	if (a==1){
		lcd_cmd(0x80);	//////////Move cursor to first line
		msdelay(4);
		lcd_write_string(display_msg2);
		lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
		lcd_write_string(display_msg3);
	}
	else{
		lcd_cmd(0x80);	//////////Move cursor to first line
		msdelay(4);
		lcd_write_string(display_msg4);
		lcd_cmd(0xC0);	//////////Move cursor to 2nd line of LCD
		lcd_write_string(display_msg5);
	}
	while(1);
		
}