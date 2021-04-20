#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <string.h> 

char* chungus[10]; 
void init(){ 
        setvbuf(stdin,NULL,_IONBF,0);
        setvbuf(stdout,NULL,_IONBF,0);
        setvbuf(stderr,NULL,_IONBF,0);
} 

void alloc(){
        int index; 
        int size; 
        char* data; 

        puts("Index: "); 

        scanf("%d", &index); 

        if (index < 0 || index >= 10){ 
                return; 
        } 
        puts("Size: "); 
        scanf("%d", &size); 

        if (size >= 0x70 || size < 0){ 
                return; 
        } 

        data = (char *)malloc(size); 

        puts("Data"); 

        read(0, data, size); 

        chungus[index] = data; 
} 
void delete(){ 
        int index; 
        puts("Index"); 
        scanf("%d", &index); 

        if (index < 0 || index >= 10){ 
                return;
        } 

        free(chungus[index]);
} 

void show(){ 
        int index; 

        puts("Index"); 

        scanf("%d", &index); 

        write(1, chungus[index], strlen(chungus[index])); 
} 
int main(){ 
        int option;
        init(); 
        char buff[100];
        printf("Enter your name for chungus access:\n");
        fgets(buff, 0x100, stdin);

        while (strncmp(buff, "OSINT", 5) != 0){
                printf("1. Malloc\n2. Show\n3. Free\n4. Exit\n> "); 
                scanf("%d", &option); 
                if (option == 1){ 
                        alloc(); 
                } 
                else if (option == 2){ 
                        show(); 
                } 
                else if (option == 3){ 
                        delete(); 
                } 
                else if (option == 4){ 
                        exit(0); 
                }
                else{ 
                        puts("Invalid option"); 
                } 


        } 

} 