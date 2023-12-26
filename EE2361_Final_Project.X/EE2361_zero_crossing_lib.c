/**
Date: 12/8/2023
Names: Jacob Xing, Alex Kaess
Short Program Description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "EE2361_buffer_lib.h"
#include <xc.h>

#define ZERO 392
#define WINDOW_SIZE 5
#define ADCBUFSIZE 1024
    
// Function: getFreq
// ---------------------------
// Disables the interrupt first so values in the ADC buffer do not change while we perform
// zero crossing detection. For more information on zero crossing visit https://en.wikipedia.org/wiki/Zero_crossing
// The midpoint of the sinusoidal wave will serve as the 'zero' in this case. Calculated from
// the hardware (microphone built in DC offset, LPF, amplifier) the zero is defined as 392. 
// Once two zero crossings has been detected, the time between the two events is calculated
// and multiplied by 2 to give the period. Re-enable the interrupt now as no more calculations
// with the buffer are being done. By taking the sampling frequency over the period, the frequency
// is found, and returned.
// return: the frequency of the input that the microphone is detecting. 
double getFreq(void) {
    IEC0bits.AD1IE = 0;     //disable the interrupt so the values in the buffer don't change while we detect the peaks
    
    int zeros[2] = {-1, -1};
    int index = 0;

    for (int i = 1; i < ADCBUFSIZE; ++i) {
        // Check for a change in "sign" (Goes across the ZERO 392)
        if ((adc_buffer[i - 1] >= ZERO && adc_buffer[i] < ZERO) || (adc_buffer[i - 1] < ZERO && adc_buffer[i] >= ZERO)) {
            zeros[index] = i;
            index++;
            if(index > 1){  //makes sure the index of the array doesn't go over the array size
                index = 0;
            }
        }
    }

    // Calculate the number of indexes between zeros
    double indexesBetweenPeaks = (zeros[1] == -1 || zeros[0] == -1) ? -1 : zeros[1] - zeros[0];
    IEC0bits.AD1IE = 1;     //re-enable the interrupt now that we are done with the computations
    double frequency = 40000/(2*indexesBetweenPeaks);
    return frequency;
}
