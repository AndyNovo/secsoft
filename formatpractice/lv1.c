#include <stdio.h>
#include <stdlib.h>

void win(void){
  printf("You win\n");
}

int main(void){
    int key = 0xdeadbeef;
    char buffer[64];
    printf("stack leak: %p\n", &key);
    fgets(buffer, 64, stdin);
    printf(buffer);
    if (key == 1337){
        win();
    }
    return 0;
}
