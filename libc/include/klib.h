#ifndef _KLIB_H
#define _KLIB_H 1

#include <sys/cdefs.h>
#include <stdio.h>

void panic(char* msg){
	printf("Kernel Panic: %s RESULT: SYSTEM HALTED", msg);
	asm("hlt");
}
#endif	
