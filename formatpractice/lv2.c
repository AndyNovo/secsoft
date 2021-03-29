#include <stdio.h>
#include <stdlib.h>

int main(void){
    char buffer[32];
    extern void * GOTCHA asm("_GLOBAL_OFFSET_TABLE_");
    printf("GOT start: %p\n", &GOTCHA);
    printf("printf leak: %p\n", printf);
    fgets(buffer, 32, stdin);
    printf(buffer);
    printf("/bin/sh");
    exit(0);
}
