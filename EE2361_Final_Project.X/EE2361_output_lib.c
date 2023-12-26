/**
Date: 12/8/2023
Names: Jacob Xing, Alex Kaess
Short Program Description:
 */

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "EE2361_buffer_lib.h"
#include "EE2361_lcd_lib.h"
#include "xc.h"

#define A3      220
#define A3S     233.08
#define B3      245.95
#define C4      261.63
#define C4S     277.18
#define D4      293.66
#define D4S     311.13
#define E4      329.63
#define F4      349.23
#define F4S     369.99
#define G4      392.00
#define G4S     415.30
#define A4      440
#define A4S     466.16
#define B4      493.88
#define C5      523.25
#define C5S     554.37
#define D5      587.33
#define D5S     622.25
#define E5      659.25
#define F5      698.46
#define F5S     739.99	
#define G5      783.99
#define G5S     830.61
#define A5      880
    
#define B3F     233.08
#define D4F     277.18
#define E4F     311.13
#define G4F     369.99
#define A4F     415.30
#define B4F     466.16    
#define D5F     554.37
#define E5F     622.25
#define G5F     739.99
#define A5F     830.61    
    
double notes[25] = {
A3,      
A3S,     
B3,      
C4,      
C4S,     
D4,      
D4S,     
E4,      
F4,      
F4S,     
G4,      
G4S,     
A4,      
A4S,     
B4,      
C5,      
C5S,     
D5,      
D5S,     
E5,      
F5,    
F5S,  	
G5,    
G5S,     
A5 };

//Space is present to overwrite the "#" on the LCD
char noteName[25][2] = {
"A ",      
"A#",     
"B ",      
"C ",      
"C#",     
"D ",      
"D#",     
"E ",      
"F ",      
"F#",     
"G ",      
"G#",     
"A ",      
"A#",     
"B ",      
"C ",      
"C#",     
"D ",      
"D#",     
"E ",      
"F ",    
"F#",  	
"G ",    
"G#",     
"A "  
};

// Function: display
// ---------------------------
// Prints "Note: " onto the LCD display. 
// Doesn't return anything
void display(void){
    lcd_setCursor(0, 0);
    lcd_printStr("Note:");
}    

int targetNote = -1;
int sharp = -1;
int inTune = 0;

// Function: findNote
// ---------------------------
// Uses a binary search algorithm to find the two nearest
// note frequencies. The geometric mean of the two notes 
// is then taken to give the halfway point between the two 
// notes. If the frequency detected is above the geometric
// mean, it is treated as the upper note, thus flat and 
// vice versa. The variable 'targetNote' will track which
// note to display. Another variable that tracks if the 
// frequency is within 0.005 of the defined note will 
// determine if the note is in tune. 
// target: frequency of sound the microphone is detecting
// Doesn't return anything.
void findNote(double target) {
    sharp = -1;         //reset if the note is sharp or flat here
    inTune = 0;         //reset if the note is in tune
    // Binary search function
    int low = 0;
    int high = 25 - 1;

    // Initialize closest indexes to the extremes of the array
    int index1 = low;
    int index2 = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Update closest values
        if (abs(notes[mid] - target) < abs(notes[index1] - target)) {
            index2 = index1;
            index1 = mid;
        } else if (abs(notes[mid] - target) < abs(notes[index2] - target)) {
            index2 = mid;
        }

        // Adjust search range
        if (notes[mid] == target) {
            // Exact match found
            index1 = index2 = mid;
            break;
        } else if (notes[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    //Checks if which value it is closer to, determining if it is flat or sharp of a note
    double upper = notes[index1];           
    double lower = notes[index2];
    int upperIndex = index1;
    int lowerIndex = index2;
    if(index1 < index2){
        upper = notes[index2];
        lower = notes[index1];
        upperIndex = index2;
        lowerIndex = index1;
    }
    double geoMean = sqrt(notes[index1] * notes[index2]);       //taking geometric mean of the two notes for the mid point
    
    //Higher note
    if(target > geoMean){
        double inTuneUp = upper * 1.005;
        double inTuneDown = upper * .995;
        targetNote = upperIndex;
        if(target > inTuneDown && target < inTuneUp){
            inTune = 1;
        }
        if(upper > target){         //note being played is lower in Hz, flat
            sharp = 0;
        } else if(upper < target){
            sharp = 1;                      //note being played is higher in Hz, sharp
        }
    } 
    //Lower note
    else if(target < geoMean){
        double inTuneUp = lower * 1.05;
        double inTuneDown = lower * 0.95;
        targetNote = lowerIndex;
        if(target > inTuneDown && target < inTuneUp){
            inTune = 1;
        }
        if(lower > target){
            sharp = 0;                      //note being played is lower in Hz, flat
        } else if(lower < target){
            sharp = 1;                      //note being played is higher in Hz, sharp
        }
    }
}

char adStr[20];

// Function: set_freq
// ---------------------------
// Sets the frequency of sound the microphone
// picks up. Used to troubleshoot whether ADC
// and hardware is working.
// frequency: frequency of sound the microphone is detecting
// Doesn't return anything.
void set_freq(double frequency){
    //Set cursor to bottom left of the screen
    lcd_setCursor(0, 1);
    sprintf(adStr, "%6.4f", frequency);
    lcd_printStr(adStr);
}

// Function: set_note
// ---------------------------
// Sets the note of the sound, as well as if
// the sound being played is flat, sharp, or 
// 'good' (as in in tune)
// frequency: frequency of sound the microphone is detecting
// Doesn't return anything.
void set_note(double frequency){
    findNote(frequency);
    //Set cursor to top of the screen, after "Note: "
    lcd_setCursor(6, 0);
    lcd_printStr(noteName[targetNote]);
    lcd_setCursor(0, 1);
    if(inTune){
        lcd_printStr("Good ");
    } else if(sharp){
        lcd_printStr("Sharp   ");
    } else if(sharp == 0){
        lcd_printStr("Flat ");
    }
}
