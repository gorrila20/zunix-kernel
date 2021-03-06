#if UINT32_MAX == UINTPTR_MAX
#define STACK_CHK_GUARD 0xe2dee396
#else
#define STACK_CHK_GUARD 0x595e9fbd94fda766
#endif
#include <stdio.h>
#include <stdint.h>
#include <kernel/tty.h>
#include <stddef.h>
#include <string.h>
#include <klib.h>
#include <kernel/gdt.h>
#include <sys/io.h>
uintptr_t __stack_chk_guard = STACK_CHK_GUARD;
static const char* version = "0.0.1 x86";
__attribute__((noreturn))
	void __stack_chk_fail(void)
{


#if __STDC_HOSTED__
	abort();
#elif __is_zunix_kernel
	panic("Stack smashing detected");
#endif
}

void kernel_main(void) {
	terminal_initialize();
	printf("[1] Welcome to zUNIX version %s! \n",version);
	init_tables(); //set up GDT tables function found in gdt.h in kernel/include
				
}
