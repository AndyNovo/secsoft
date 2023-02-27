#include <stdio.h>
#include <stdlib.h>

int vuln(void){
   char home[512];
   fgets(home, 1024, stdin);
   return 0;
}


int main(void){
   int x = 23;
   printf("Turtle time... %p\n", &x);
   vuln();
   return 0;
}
