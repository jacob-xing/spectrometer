/* 
 * File:   output_lib.h
 * Authors: Jacob Xing, Alex Kaess
 *
 * Created on November 27, 2023, 5:53 PM
 */

#ifndef OUTPUT_LIB_H
#define	OUTPUT_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif
   

// Function: display
// ---------------------------
// Prints "Note: " onto the LCD display. 
// Doesn't return anything
void display(void);    


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
void findNote(double target);

// Function: set_freq
// ---------------------------
// Sets the frequency of sound the microphone
// picks up. Used to troubleshoot whether ADC
// and hardware is working.
// frequency: frequency of sound the microphone is detecting
// Doesn't return anything.
void set_freq(double frequency);

// Function: set_note
// ---------------------------
// Sets the note of the sound, as well as if
// the sound being played is flat, sharp, or 
// 'good' (as in in tune)
// frequency: frequency of sound the microphone is detecting
// Doesn't return anything.
void set_note(double frequency);

#ifdef	__cplusplus
}
#endif

#endif	/* OUTPUT_LIB_H */

