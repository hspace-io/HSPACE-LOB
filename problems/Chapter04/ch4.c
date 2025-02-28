#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

char MasterKey[16] = "/bin/sh";

void initialize() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

void gadget() {
    asm("pop %rdi; ret");
    asm("pop %rsi; pop %r15; ret");
    asm("pop %rdx; ret");
    }

void welcom(){
    printf("Welcome to the shop\n");
    printf("[1] Vegetable Display\n");
    printf("[2] Frozen Food Display\n");
    printf("[3] Ramen/Snack Display\n");
}

int main(int argc, char *argv[]){

    int select;
    char buf[0x40]={};
    initialize();
    welcom();

    printf("Choose the display stand : ");
    scanf("%d", &select);
    if(select == 1 || select == 3)
    {
        printf("Remaining quantity : 0");
        printf("There are no items left.");
    }
    else if(select == 2)
    {
        printf("Remaining quantity : 30\n");
        printf("Frozen food is stored in the freezer warehouse.\n");
        printf("Address of freezer warehouse : %p\n", &read);
        printf("Please select the quantity of the item : ");
        read(0,buf,0x400);
    }



    write(1, buf, sizeof(buf));

    return 0;
}