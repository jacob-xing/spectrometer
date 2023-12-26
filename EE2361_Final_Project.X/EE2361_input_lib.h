/* 
 * File:   input_lib.h
 * Authors: Jacob Xing, Alex Kaess
 *
 * Created on November 27, 2023, 5:53 PM
 */


#ifndef INPUT_LIB_H
#define	INPUT_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif
    
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
void mic_init();    

// Function: _T1Interrupt
// ---------------------------
// Uses Timer1 to store the frequencies into a buffer.
// This is an interrupt service routine.
// Doesn't return anything
void __attribute__((interrupt, auto_psv)) _T1Interrupt();

// Function: _ADC1Interrupt
// ---------------------------
// Uses Timer3 to store the values of the analog to digital conversion (ADC)
// into a buffer to recreate the analog signal sent by the microphone. The
// values stored in the buffer are digital as they have been converted
// from analog.
// This is an interrupt service routine.
// Doesn't return anything
void __attribute__((__interrupt__, __auto_psv__)) _ADC1Interrupt(void);  




#ifdef	__cplusplus
}
#endif

#endif	/* INPUT_LIB_H */

