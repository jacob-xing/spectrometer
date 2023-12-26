/**
Date: 12/8/2023
Names: Jacob Xing, Alex Kaess
Short Program Description:
 */

#include "stdio.h"
#include "stdlib.h"
#include "xc.h"

// Function: delay_ms
// ---------------------------
// A simple delay function that
// repeats nop instructions to
// create a delay
// ms: the time the delay will take in ms
void delay_ms(unsigned int ms){
    while(ms-- > 0){
        asm("repeat #15998");
        asm("nop");
    }
}

// Function: lcd_cmd
// ---------------------------
// Sends a package of bits using I2c
// package: a string of bits (0 or 1)
void  lcd_cmd(char package){
    //Send Start
    IFS3bits.MI2C2IF = 0;
    I2C2CONbits.SEN = 1;
    while(I2C2CONbits.SEN==1);
    
    //Send Address and Write Command
    I2C2TRN = 0b01111100;
    IFS3bits.MI2C2IF = 0;
    while(IFS3bits.MI2C2IF == 0);
    
    //Send high byte (always 0x00)
    I2C2TRN = 0b00000000;
    IFS3bits.MI2C2IF = 0;
    while(IFS3bits.MI2C2IF == 0);
    
    //Send Package
    I2C2TRN = package;
    IFS3bits.MI2C2IF = 0;
    while(IFS3bits.MI2C2IF == 0);
    
    //Send Stop
    IFS3bits.MI2C2IF = 0;
    I2C2CONbits.PEN = 1;
    while(I2C2CONbits.PEN == 1);
}

// Function: lcd_init
// ---------------------------
// Sets up the LCD screen with I2C
void lcd_init(void){
    I2C2BRG = 0x9D;
    IFS3bits.MI2C2IF = 0;
    I2C2CONbits.I2CEN = 1;
    
    delay_ms(40);
    
    lcd_cmd(0b00111000);
    lcd_cmd(0b00111001);
    lcd_cmd(0b00010100);
    lcd_cmd(0b01110000);
    lcd_cmd(0b01010110);
    lcd_cmd(0b01101100);
    
    delay_ms(200);
    
    lcd_cmd(0b00111000);
    lcd_cmd(0b00001100);
    lcd_cmd(0b00000001);
    
    delay_ms(1);
}

// Function: lcd_setCursor
// ---------------------------
// Sets where the first char will
// be printed on the LCD screen
// The top-left most of the LCD
// screen is (0, 0) in the form
// (column, row))
// x: the column of the LCD screen
// y: the row of the LCD screen
void lcd_setCursor(char x, char y){
    lcd_cmd(0x80 + (0x40*y + x));
}

// Function: lcd_printChar
// ---------------------------
// Prints a single character onto
// the LCD screen based off the
// ASCII table using I2C.
// myChar: character to display on the LCD screen
void lcd_printChar(char myChar){
    I2C2CONbits.SEN = 1;	//Initiate Start condition
    while(I2C2CONbits.SEN == 1);  // SEN will clear when Start Bit is complete
    IFS3bits.MI2C2IF = 0;
    I2C2TRN = 0b01111100; // 8-bits consisting of the slave address and the R/nW bit
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
    I2C2TRN = 0b01000000; // 8-bits consisting of control byte /w RS=1
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
    I2C2TRN = myChar; // 8-bits consisting of the data byte
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
    I2C2CONbits.PEN = 1;
    while(I2C2CONbits.PEN == 1); // PEN will clear when Stop bit is complete
}

// Function: lcd_printStr
// ---------------------------
// Prints a string of characters onto the LCD 
// screen based off the ASCII table using I2C.
// A while loop is used as we don't want to 
// keep resending the start bit during the string.
// s: string of characters to display on the LCD screen
void lcd_printStr(const char s[]){
    I2C2CONbits.SEN = 1;	//Initiate Start condition
    while(I2C2CONbits.SEN == 1);  // SEN will clear when Start Bit is complete
    IFS3bits.MI2C2IF = 0;
    I2C2TRN = 0b01111100; // 8-bits consisting of the slave address and the R/nW bit
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
    int i = 0;          //counter
    while(s[i+1] != NULL){
        I2C2TRN = 0b11000000; // 8-bits consisting of control byte /w RS=1
        while(IFS3bits.MI2C2IF == 0);
        IFS3bits.MI2C2IF = 0;
        I2C2TRN = s[i];
        while(IFS3bits.MI2C2IF == 0);
        IFS3bits.MI2C2IF = 0;
        i++;
    }
    I2C2TRN = 0b01000000; // 8-bits consisting of control byte /w RS=1
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
    I2C2TRN = s[i];
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
    I2C2CONbits.PEN = 1;
    while(I2C2CONbits.PEN == 1); // PEN will clear when Stop bit is complete
    
}
