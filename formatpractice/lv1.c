#include <stdio.h>
#include <stdlib.h>

void win(void){
  printf("You win\n");
}

int main(void){
    int key = 1337;
    char buffer[32];
    printf("stack leak: %p\n", &key);
    fgets(buffer, 32, stdin);
    printf(buffer);
    if (key == 0xdeadbeef){
        win();
    }
    exit(0);
}
