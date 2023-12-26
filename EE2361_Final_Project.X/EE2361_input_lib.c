/**
Date: 12/8/2023
Names: Jacob Xing, Alex Kaess
Short Program Description:
 */

#include "xc.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "math.h"
#include "EE2361_zero_crossing_lib.h"
#include "EE2361_buffer_lib.h"

// Function: mic_init
// ---------------------------
// Initializes the pic for A/D conversion with Timer3. 
// Timer1 is also initialized here.
// Pin 2 on the PIC24FJ64GA002 is set to input as that
// is where the microphone is connected to. To get a
// sampling frequency of 40000, PR3 is set to 399 from
// the equation commented below. Tcy is 62.5ns. Make sure
// to set sampling frequency based on needs of specific 
// requirements and Nyquist's theorem.
void mic_init(){
    TRISAbits.TRISA0 = 1;       //set to input
    
    AD1PCFGbits.PCFG0 = 0;      //setup I/O
    
    AD1CON2bits.VCFG = 0b000;   
    AD1CON3bits.ADCS = 1;           
    AD1CON1bits.SSRC = 0b010;
    AD1CON3bits.SAMC = 1;           
    AD1CON1bits.FORM = 0;
    AD1CON1bits.ASAM = 1;
    AD1CON2bits.SMPI = 0;       //Samples after every interrupt
    AD1CON1bits.ADON = 1;   
    
    IFS0bits.AD1IF = 0;
    IEC0bits.AD1IE = 1;
    
    TMR3 = 0;
    T3CON = 0;
    T3CONbits.TCKPS = 0;
    PR3 = 399;                  // 1/freq = (PR3+1)*Tcy*PRE gives us a sampling frequency of 400000Hz
    T3CONbits.TON = 1;
    
    //Timer1 initialization for frequency sampling
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
    TMR1 = 0;
    T1CON = 0;
    T1CONbits.TCKPS = 2;
    PR1 = 12500;
    T1CONbits.TON = 1;
}    
    
volatile int adValue;
unsigned int counter = 0;

volatile double temp_freq;

// Function: _T1Interrupt
// ---------------------------
// Uses Timer1 to store the frequencies into a buffer.
// This is an interrupt service routine.
// Doesn't return anything
void __attribute__((interrupt, auto_psv)) _T1Interrupt(){
    temp_freq = getFreq();
    putValFreq(temp_freq);        
    IFS0bits.T1IF = 0; 
}

// Function: _ADC1Interrupt
// ---------------------------
// Uses Timer3 to store the values of the analog to digital conversion (ADC)
// into a buffer to recreate the analog signal sent by the microphone. The
// values stored in the buffer are digital as they have been converted
// from analog.
// This is an interrupt service routine.
// Doesn't return anything
void __attribute__((__interrupt__, __auto_psv__)) _ADC1Interrupt(void)
{
    IFS0bits.AD1IF = 0;
    adValue = ADC1BUF0;         //Set the voltage value
    counter++;
    putValAdc(adValue);            //put the value into the buffer
}  
