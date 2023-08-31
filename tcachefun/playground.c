#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

extern void * _IO_list_all;

char menu[] = "You are using %d/100 chunk addresses.\n1. New\n2. Delete\n3. Edit \n4. View data\n5. Exit\n> ";
int space = 0;
char* arr[100];
int arr_size[100];

int menu_malloc(){
    int idx, sz;
    printf("which index?\n> ");
    scanf("%d", &idx);
    getchar();
    printf("how big?\n> ");
    scanf("%d", &sz);
    getchar();
    if ((idx >= 0) && (idx < 100)){
        arr[idx] = malloc(sz);
	arr_size[idx] = sz;
	space++;
    } else {
	printf("Invalid request\n");
	return 1;
    }
    printf("first payload?\n> ");
    fgets(arr[idx], sz, stdin);
    return 0;
}

int menu_free(){
    int idx;
    printf("which index?\n> ");
    scanf("%d", &idx);
    getchar();
    if ((idx >= 0) && (idx < 100)){
        free(arr[idx]);
	space--;
    } else {
	printf("Invalid request\n");
	return 1;
    }
    return 0;
}

int menu_edit(){
    int idx;
    printf("which index?\n> ");
    scanf("%d", &idx);
    getchar();
    if ((idx >= 0) && (idx < 100)){
	printf("New contents?\n> ");
	fgets(arr[idx], arr_size[idx] + 64, stdin);
    } else {
	printf("Invalid request\n");
	return 1;
    }
    return 0;
}

int menu_view(){
    int idx;
    printf("which index?\n> ");
    scanf("%d", &idx);
    getchar();
    if ((idx >= 0) && (idx < 100)){
        puts(arr[idx]);
    } else {
	printf("Invalid request\n");
	return 1;
    }
    return 0;
}

int main(){
    int choice;
    setvbuf(stdin, NULL, _IONBF, 1);
    setvbuf(stdout, NULL, _IONBF, 1);
    while (1) {
        printf(menu, space);
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            menu_malloc();
            break;

        case 2:
            menu_free();
            break;

        case 3:
            menu_edit();
            break;

        case 4:
            menu_view();
            break;

        case 5:
            exit(0);
            break;

        default:
            break;
        }
    }
    return 0;
}
