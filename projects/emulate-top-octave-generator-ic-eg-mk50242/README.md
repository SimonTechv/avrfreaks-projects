# Emulate a Top Octave Generator IC (e.g. MK50242)

Uploaded by ajcashin on 2018-12-09 22:58:00 (rating 0 out of 5)

## Summary

In the 1970s, electronic instruments were made that used a Top Octave Generator (TOG) IC. Almost all of the TOGs took an input frequency derived from a 2 MHz crystal oscillator circuit and provided twelve or thirteen square waves of the right pitches by dividing this input frequency by factors from 239 to 478. This provided square waves with frequencies between 4434 and 8368 Hz. Lower frequencies were generated by dividing each output through counter ICs, providing each input frequency divided by a power of 2.


People repairing these instruments can source suitable divider ICs, but the TOG ICs are no longer made. Custom chips or old stock are available, but are expensive. An alternate is to provide a software solution for a cheap computer chip. The author purchased several Arduino Pro Mini boards for a project, nothing to do with TOGs. Creating the software TOG was a learning exercise to become familiar with the Arduino environment. The program is in assembler, and was written for a 16MHz ATmega328P. A Pro Mini with a 16MHz crystal and ATmega328P processor was purchased from overseas for less than $3. The .hex file was created using AtmelStudio 7, and programmed into the Pro Mini using avrdude.exe driving an Arduino compatible FIDI FT232RL USB To Serial Adapter (also costing less than $3).


The program was written to be a faithful emulation of a TOG IC driven by a 2MHz clock. The ICs attempt to produce an equal tempered scale, where the note pitches are based on the twelfth root of two. This is the scale in common use for instruments with fixed tuning such as pianos. The TOG IC notes are not exact, but close approximations. Because the ATmega328P has a 16MHz clock the periods used in the program are 4 times the dividers used in the TOG. The periods for some notes can be adjusted in the program to be closer to the equal tempered scale pitches. The downside of doing this is the outputs have to align with a notional 2MHz clock so appear to jitter. When the signal is feeding a divider, the jitter disappears after dividing by 8. It is an area for experimentation.


Another area for experimentation is using different scales. The period information is held in flash memory, and copied into RAM as part of the initialisation process. There is enough spare flash memory to have hundreds of 12-note scales, a selection mechanism would be needed to decide which scale to copy to RAM. The program is written so that in idle time the flash memory data is repeatedly copied to RAM. This is not required when using a single scale, but opens the opportunity to change scales on the fly.


The processing required is near the limit of what can be done with the ATmega328P so the program is in assembler, and is optimised for speed at the expense of duplicating a lot of code. This minimises branch instructions and there are no subroutines. Because there is a lot of duplication, much of the code is generated by using macros. Much use is made of 'bit twiddling' e.g. capturing the state of the C flag with a Rotate Right through Carry instruction then retrieving it later with a Logical Shift Left. This is not an example of good programming practice, but it is an example of extracting the most out of the processor.

## Links

- [Studio 7 assembler for a Top Octave Generator](https://drive.google.com/file/d/1iy8ny06Aqs-ViIY1kYO1YyXoGr4Bj2kG/view?usp=sharing)

## Compilers

- AVR Assembler

## Tags

- Complete code
- AVR Assembler
- #arduino #Atmega #Atmega328p
- electronic organs
- TOG
- Home Entertainment