# Tuner System
This project is a tuner system capable of automatically identifying the frequency of an audio input and determining its proximity to the nearest defined note. The system currently supports a range of A3 to A5, and expanding this range can be easily accomplished without altering the underlying code structure (simply create more notes with #define).
The MAX9814 microphone is employed to capture the audio signal, which is then sent through a low pass filter to reduce noice (cutoff frequency of 7 kHz), then a buffer amplifier. The signal is then converted from analog to digital by the microcontroller. Utilizing zero-crossing detection, the digital values recreate the signal, allowing for accurate frequency determination. The microcontroller then identifies the two nearest defined notes and computes the closest note based on frequency. The sampling frequency is at 40 kHz, following Nyquist's Theorem which states the sampling frequency must be greater than twice of the max frequency the microcontroller will receive (7 kHz) to avoid aliasing. 
To convey this information, the microcontroller employs the I2C protocol to communicate with an LCD screen. The LCD screen displays not only the identified note but also indicates whether the note is flat, sharp, or in tune.

Schematic of the Tuner:
<img width="978" alt="Screenshot 2023-12-26 at 2 11 01 PM" src="https://github.com/jacob-xing/spectrometer/assets/121461222/7f8e7ce5-5e8e-4ac6-adaf-1938b2bf48c1">

## Hardware
[Microchip PIC24FJ64GA002 Microcontroller](https://www.microchip.com/en-us/product/pic24fj64ga002)

[Electret Microphone Amplifier MAX9814](https://www.adafruit.com/product/1713)

[I2C Small LCD Board (3.3V)](https://international.switch-science.com/catalog/1405/)

[Microchip Snap Programmer](https://www.microchip.com/en-us/development-tool/PG164100)

[LT1006 Single Supply Op Amp](https://www.digikey.com/en/products/detail/analog-devices-inc/LT1006S8-TRPBF/960108)

Resistors
  The following resistor values were used: 10 Ω, 1000 Ω, 10000 Ω.
Capacitors
  The following capacitor values were used: 2.2 μF, 10 nF.


## Input Library
  ### void mic_init()
    Description: Initializes the PIC24FJ64GA002 for A/D conversion with Timer3 as well as initializing Timer 1 for sampling frequency.
    Arguments: No arguments.
    Returns: No returns.
    
## Signal Processing Library
  ### double getFreq()
    Description: Utilizes the zero-crossing signal processing method to calculate and return the frequency of the signal input to the ADC.
    Arguments: No arguments.
    Returns: A double representing the calculated frequency.
    
## Buffer Library
  ### void initAdcBuffer()
    Description: Initializes the ADC circular buffer for use.
    Arguments: No arguments.
    Returns: No returns.
  ### void putValAdc (unsigned int val);
    Description: Puts a value in the ADC circular buffer.
    Arguments: ‘val’: an unsigned integer to be placed in the ADC buffer.
    Returns: No returns
  ### void initFreqBuffer()
    Description: Initializes the Frequency circular buffer for use.
    Arguments: No arguments.
    Returns: No returns.
  ### void putValFreq (unsigned int val)
    Description: Puts a value in the Frequency circular buffer.
    Arguments: ‘val’: an unsigned integer to be placed in the frequency buffer.
    Returns: No returns.
  ### int compareIntegers(const void *a, const void *b)
    Description: Compares two integers for quick sort.
    Arguments: 
      ‘*a’: A pointer to the first variable to compare
      ‘*b’: A pointer to the second variable to compare
    Returns: If the first integer is less than the second, the function returns a negative value; if they are equal, it returns zero, and if the first integer is greater than the second, it returns a positive value.
  ### double getMedian(void)
    Description: Finds and returns the median value of the frequency circular buffer.
    Arguments: No arguments.
    Returns: A double representing the median value of the frequency circular buffer.
    
## LCD Library
  ### void delay_ms(unsigned int ms)
    Description: A simple delay function that  repeats nop instructions to create a delay.
    Arguments: ‘ms’: the time the delay will take in ms.
    Returns: No returns.
  ### void  lcd_cmd(char package)
    Description: Sends a package of bits using I2C.
    Arguments: ‘package’: a string of bits (0 or 1).
    Returns: No returns.
  ### void lcd_init(void)
    Description: Sets up the LCD screen with I2C protocol.
    Arguments: No arguments.
    Returns: No returns.
  ### void lcd_setCursor(char x, char y)
    Description: Sets where the first char will be printed on the LCD screen. The top-left most of the LCD screen is (0, 0) in the form (column, row)).
    Arguments:
      ‘x’: the column of the LCD screen.
      ‘y’: the row of the LCD screen.
    Returns: No returns.
  ### void lcd_printChar(char myChar)
    Description: Prints a single character onto the LCD screen based off the ASCII table using I2C.
    Arguments: ‘myChar’: character to display on the LCD screen.
    Returns: No returns.
  ### void lcd_printStr(const char s[ ])
    Description: Prints a string of characters onto the LCD screen based off the ASCII table using I2C. A while loop is used as we don't want to keep resending the start bit during the string.
    Arguments: ‘s’: string of characters to display on the LCD screen.
    Returns: No returns.
    
## Output Library
  ### void display(void)
    Description: Prints “note” on the LCD.
    Arguments: No arguments.
    Returns: No returns.
  ### void findNote(double target)
    Description: Uses a binary search algorithm to find the two nearest note frequencies. The geometric mean of these notes is calculated to determine the halfway point. If the detected frequency is above the geometric mean, it is considered the upper note (flat), and vice versa.
    Arguments: ‘target’: a double representing the target frequency to find the closest note.
    Returns: No returns. 
  ### void set_freq(double frequency)
    Description: Sets the frequency of sound the microphone picks up. Used to troubleshoot whether ADC and hardware is working.
    Arguments: ‘frequency’: a double representing the frequency of sound the microphone is detecting.
    Returns: No returns.
  ### void set_note(double frequency)
    Description: Sets the note of the sound, as well as if the sound being played is flat, sharp, or  'good' (as in in tune).
    Arguments: ‘frequency’: a double representing the frequency of sound the microphone is detecting.
    Outputs: No returns.
