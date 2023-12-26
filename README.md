# Spectrometer
This project is a tuner system capable of automatically identifying the frequency of an audio input and determining its proximity to the nearest defined note. The system currently supports a range of A3 to A5, and expanding this range can be easily accomplished without altering the underlying code structure (simply create more notes with #define).
The MAX9814 microphone is employed to capture the audio signal, which is then sent through a low pass filter to reduce noice (cutoff frequency of 7 kHz), then a buffer amplifier. The signal is then converted from analog to digital by the microcontroller. Utilizing zero-crossing detection, the digital values recreate the signal, allowing for accurate frequency determination. The microcontroller then identifies the two nearest defined notes and computes the closest note based on frequency. The sampling frequency is at 40 kHz, following Nyquist's Theorem which states the sampling frequency must be greater than twice of the max frequency the microcontroller will receive (7 kHz) to avoid aliasing. 
To convey this information, the microcontroller employs the I2C protocol to communicate with an LCD screen. The LCD screen displays not only the identified note but also indicates whether the note is flat, sharp, or in tune.
<img width="978" alt="Screenshot 2023-12-26 at 2 11 01 PM" src="https://github.com/jacob-xing/spectrometer/assets/121461222/7f8e7ce5-5e8e-4ac6-adaf-1938b2bf48c1">
