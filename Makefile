C = avr-gcc
LDFLAGS ?= -mmcu=atmega328p 
CFLAGS ?= -Os -DF_APU=16000000UL $(LDFLAGS)
PORT ?= /dev/ttyACM0


all: led.hex
led.hex: led
	avr-objcopy -O ihex -R .eeprom led led.hex
led: led.o display_time.o
	avr-gcc $(LDFLAGS) -o  $@ $^
led.o: light.c
	avr-gcc $(CFLAGS) -c -o $@ $<
display_time.o: display_time.c display_time.h
	avr-gcc $(CFLAGS) -c -o $@ $<
deploy: led.hex
	avrdude -F -V -c arduino  -p atmega328p -P $(PORT) -b 115200 -U flash:w:led.hex

clean:
	rm led*
