/* 
 * File:   main.c
 * Author: Jacob Xing, Alex Kaess
 *
 * Created on November 27, 2023, 5:49 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "xc.h"

#include "EE2361_buffer_lib.h"
#include "EE2361_lcd_lib.h"

#include "EE2361_output_lib.h"
#include "EE2361_zero_crossing_lib.h"
#include "EE2361_input_lib.h"


// CW1: FLASH CONFIGURATION WORD 1 (see PIC24 Family Reference Manual 24.1)
#pragma config ICS = PGx1          // Comm Channel Select (Emulator EMUC1/EMUD1 pins are shared with PGC1/PGD1)
#pragma config FWDTEN = OFF        // Watchdog Timer Enable (Watchdog Timer is disabled)
#pragma config GWRP = OFF          // General Code Segment Write Protect (Writes to program memory are allowed)
#pragma config GCP = OFF           // General Code Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF        // JTAG Port Enable (JTAG port is disabled)


// CW2: FLASH CONFIGURATION WORD 2 (see PIC24 Family Reference Manual 24.1)
#pragma config I2C1SEL = PRI       // I2C1 Pin Location Select (Use default SCL1/SDA1 pins)
#pragma config IOL1WAY = OFF       // IOLOCK Protection (IOLOCK may be changed via unlocking seq)
#pragma config OSCIOFNC = ON       // Primary Oscillator I/O Function (CLKO/RC15 functions as I/O pin)
#pragma config FCKSM = CSECME      // Clock Switching and Monitor (Clock switching is enabled, 
                                       // Fail-Safe Clock Monitor is enabled)
#pragma config FNOSC = FRCPLL      // Oscillator Select (Fast RC Oscillator with PLL module (FRCPLL))

/*
 * 
 */
#define FILE_NAME "data.txt"

void pic24_init(){
    CLKDIVbits.RCDIV = 0;
    AD1PCFG = 0x9fff;
}

//A function to initialize everything to keep main simple
void setup(){
    pic24_init();
    lcd_init();
    initAdcBuffer();
    initFreqBuffer();
    mic_init();
}


int main(void) {
    setup();
    display();      //Display "Note:" on LCD first
    unsigned int freq = 0;
    while(1){
        delay_ms(500);
        freq = getMedian();
        set_note(freq);
    }
    return 0;
}
