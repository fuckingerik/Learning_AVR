#!/bin/bash
avr-gcc -g -Os -mmcu=atmega328 -c helloworld.c
avr-gcc -g -mmcu=atmega328 -o helloworld.elf helloworld.o
avr-objcopy -j .text -j .data -O ihex helloworld.elf helloworld.hex
echo "DONE"
