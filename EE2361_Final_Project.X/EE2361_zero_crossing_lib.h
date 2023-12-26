/* 
 * File:   EE2361_fft_lib.h
 * Author: Jacob
 *
 * Created on November 27, 2023, 6:55 PM
 */

#ifndef EE2361_FFT_LIB_H
#define	EE2361_FFT_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif    
    
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
double getFreq(void);


#ifdef	__cplusplus
}
#endif

#endif	/* EE2361_FFT_LIB_H */

