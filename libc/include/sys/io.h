#ifndef __IO_H
#define __IO_H
#include <stdint.h>
#include <stdio.h>
static inline void outb(uint16_t port, uint8_t value){
	asm volatile ( "outb %0, %1" : : "a"(value), "Nd"(port) );
}
static inline uint8_t inb (uint16_t port){
	uint8_t ret;
	asm volatile ("inb %1, %0"
			: "=a"(ret)
			: "Nd"(port) );
	return ret;
}
static inline void io_wait(void){

	asm volatile ("outb %%al, $0x80" : : "a"(0) );

}
#endif
