#include <stdio.h>
#include <stdlib.h>

int main(void){
	extern void * GOTCHA asm("_GLOBAL_OFFSET_TABLE_");
	printf("GOTCHA: %p\n", &GOTCHA);
	printf("GET GOT: %p\n", printf);
	gets(&GOTCHA);
	printf("Nice work\n");
	return 0;
}
