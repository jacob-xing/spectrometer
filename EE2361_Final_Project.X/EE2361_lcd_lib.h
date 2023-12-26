/* 
 * File:   EE2361_lcd_lib.h
 * Authors: Jacob Xing, Alex Kaess
 *
 * Created on November 27, 2023, 7:09 PM
 */

#ifndef EE2361_LCD_LIB_H
#define	EE2361_LCD_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

// Function: delay_ms
// ---------------------------
// A simple delay function that
// repeats nop instructions to
// create a delay
// ms: the time the delay will take in ms
void delay_ms(unsigned int ms);

// Function: lcd_cmd
// ---------------------------
// Sends a package of bits using I2c
// package: a string of bits (0 or 1)
void  lcd_cmd(char package);

// Function: lcd_init
// ---------------------------
// Sets up the LCD screen with I2C
void lcd_init(void);

// Function: lcd_setCursor
// ---------------------------
// Sets where the first char will
// be printed on the LCD screen
// The top-left most of the LCD
// screen is (0, 0) in the form
// (column, row))
// x: the column of the LCD screen
// y: the row of the LCD screen
void lcd_setCursor(char x, char y);

// Function: lcd_printChar
// ---------------------------
// Prints a single character onto
// the LCD screen based off the
// ASCII table using I2C.
// myChar: character to display on the LCD screen
void lcd_printChar(char myChar);

// Function: lcd_printStr
// ---------------------------
// Prints a string of characters onto the LCD 
// screen based off the ASCII table using I2C.
// A while loop is used as we don't want to 
// keep resending the start bit during the string.
// s: string of characters to display on the LCD screen
void lcd_printStr(const char s[]);


#ifdef	__cplusplus
}
#endif

#endif	/* EE2361_LCD_LIB_H */

