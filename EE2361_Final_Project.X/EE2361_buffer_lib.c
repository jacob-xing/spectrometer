/**
Date: 12/8/2023
Names: Jacob Xing, Alex Kaess
Short Program Description:
 */

#include "xc.h"
#include "stdlib.h"

#define ADCBUFSIZE 1024
#define FREQBUFSIZE 16
    

volatile unsigned int time = 0;
volatile int adc_buffer[ADCBUFSIZE];
volatile int adc_buffer_index = 0;    

volatile int freq_buffer[FREQBUFSIZE];
volatile int freq_buffer_index = 0;    
    

// Function: initAdcBuffer
// ---------------------------
// Initializes an empty buffer the size of the ADCBUFSISZE filled with 0's.
// Doesn't return anything.
void initAdcBuffer(){
    int i;
    for(i = 0; i < ADCBUFSIZE; i++)
        adc_buffer[i] = 0;
}

// Function: putValADC
// ---------------------------
// Puts the ADC values into the ADC buffer for later use.
// Doesn't return anything.
void putValAdc (unsigned int val){
    adc_buffer[adc_buffer_index++] = val;
    if(adc_buffer_index >= ADCBUFSIZE)
        adc_buffer_index = 0;
}

// Function: initFreqBuffer
// ---------------------------
// Initializes an empty buffer the size of the FREQBUFSIZE filled with 0's.
// Doesn't return anything.
void initFreqBuffer(){
    int i;
    for(i = 0; i < FREQBUFSIZE; i++)
        freq_buffer[i] = 0;
}

// Function: putValFreq
// ---------------------------
// Puts the frequency values into the frequency value buffer for later use
// Doesn't return anything.
void putValFreq (unsigned int val){
    freq_buffer[freq_buffer_index++] = val;
    if(freq_buffer_index >= FREQBUFSIZE)
        freq_buffer_index = 0;
}

// Function: getAvg
// ---------------------------
// Finds the average of the frequency buffer
// returns: the average value of the frequency value buffer as a double
double getAvg(){
    unsigned int sum = 0;
    for(int i = 0; i < FREQBUFSIZE; i++)
        sum += freq_buffer[i];
    return sum/FREQBUFSIZE;
}

// Function: compareIntegers
// ---------------------------
// Compares two integers for quick sort
// a: first integer
// b: second integer
// Doesn't return anything.
int compareIntegers(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function: getMedian
// ---------------------------
// Function to calculate the median of an array
// Doesn't return anything.
double getMedian(void) {
    // Sort the array in ascending order
    qsort(freq_buffer, FREQBUFSIZE, sizeof(int), compareIntegers);

    // Calculate the median
    if (FREQBUFSIZE % 2 == 0) {
        // If the size is even, average the middle two elements
        return (freq_buffer[FREQBUFSIZE / 2 - 1] + freq_buffer[FREQBUFSIZE / 2]) / 2.0;
    } else {
        // If the size is odd, return the middle element
        return freq_buffer[FREQBUFSIZE / 2];
    }
}