#include <stdio.h>
#include <stdlib.h>

void init(){
    setvbuf(stdin,NULL,_IONBF,0);
    setvbuf(stdout,NULL,_IONBF,0);
    setvbuf(stderr,NULL,_IONBF,0);
}

void win(unsigned int x){
    system("/bin/sh");
}

void vuln(){
  char name[256];
  char team[256];  
  printf("Hello what is your name?\n");
  fgets(name, 256, stdin);
  printf("Hello, ");
  printf(name);
  printf(". It's so nice to meet you!\n  What is your favorite NFL team?\n");
  fgets(team, 256, stdin);
  printf("Oh really?  You like the ");
  printf(team);
  printf("? I like the Stealers... \n");
  gets(name);
  return;
}


int main(void){
  init();
  vuln();
  return 0;
}
