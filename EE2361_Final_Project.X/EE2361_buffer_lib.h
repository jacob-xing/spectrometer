/* 
 * File:   EE2361_buffer_lib.h
 * Author: xing0063
 *
 * Created on November 30, 2023, 12:02 PM
 */

#ifndef EE2361_BUFFER_LIB_H
#define	EE2361_BUFFER_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif
 
#define ADCBUFSIZE 1024
#define FREQBUFSIZE 16
    

extern volatile int adc_buffer[ADCBUFSIZE]; 

extern volatile int freq_buffer[FREQBUFSIZE]; 
    
// Function: initAdcBuffer
// ---------------------------
// Initializes an empty buffer the size of the ADCBUFSISZE filled with 0's.
// Doesn't return anything.
void initAdcBuffer();

// Function: putValADC
// ---------------------------
// Puts the ADC values into the ADC buffer for later use.
// Doesn't return anything.
void putValAdc (unsigned int val);

// Function: initFreqBuffer
// ---------------------------
// Initializes an empty buffer the size of the FREQBUFSIZE filled with 0's.
// Doesn't return anything.
void initFreqBuffer();

// Function: putValFreq
// ---------------------------
// Puts the frequency values into the frequency value buffer for later use
// Doesn't return anything.
void putValFreq (unsigned int val);

// Function: getAvg
// ---------------------------
// Finds the average of the frequency buffer
// returns: the average value of the frequency value buffer as a double
double getAvg();

// Function: compareIntegers
// ---------------------------
// Compares two integers for quick sort
// a: first integer
// b: second integer
// Doesn't return anything.
int compareIntegers(const void *a, const void *b);

// Function: getMedian
// ---------------------------
// Function to calculate the median of an array
// Doesn't return anything.
double getMedian(void);



#ifdef	__cplusplus
}
#endif

#endif	/* EE2361_BUFFER_LIB_H */

