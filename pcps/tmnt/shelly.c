#include <stdio.h>
#include <stdlib.h>

void init(){
    setvbuf(stdin,NULL,_IONBF,0);
    setvbuf(stdout,NULL,_IONBF,0);
    setvbuf(stderr,NULL,_IONBF,0);
}

int vuln(void){
   char home[512];
   fgets(home, 1024, stdin);
   return 0;
}


int main(void){
   int x = 23;
   init();
   
   printf("Turtle time... %p\n", &x);
   vuln();
   return 0;
}
