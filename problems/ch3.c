//Stage3 of BOF expedition
//Compile : gcc -m32 -fno-stack-protector -mpreferred-stack-boundary=2 -z execstack -no-pie -o stage3 stage3.c

#include<stdio.h>
#include<stdlib.h>

int check_value = 0;

void shell()
{
    check_value = 1;
    printf("You Open the Armory Door!\n\n");
    system("/bin/sh");
}

void Power_Supply()
{
    printf("Armory lights up!\n\n");
}

void Power_cut_off()
{
    printf("The lights go out in the armory!\n\n");
}

void Weapon_Select()
{
    int weapon_choice;

    if(check_value != 1)
    {
        printf("You must be open the door!\n\n");
    }
    else
    {
        printf("Weapon List\n");
        printf("[1] Knife\n");
        printf("[2] Gun\n");
        printf("[3] Frying Pan\n");
        printf("[4] Baseball Bet\n");

        printf("Select a Weapon : ");
        scanf("%d", &weapon_choice);
        
        switch (weapon_choice) {
        case 1:
            printf("[Knife] I got it!\n\n");
            break;
        case 2:
            printf("[Gun] I got it!\n\n");
            break;
        case 3:
            printf("[Frying Pan] I got it!\n\n");
            break;
        case 4:
            printf("[Baseball] I got it!\n\n");
            break;
        default:
            printf("Wrong input!\n");
            break;
        }
    }
}

void Open_Door()
{
    char password[20];
    
    printf("Enter Password : ");
    scanf("%s", password);
}

void Close_Door()
{
    if(check_value ==  0)
    {
        printf("The door is already closed\n\n");
    }
}

void Check_Security_System_Log()
{
    printf("Arch:     i386-32-little\n");
    printf("RELRO:    Partial RELRO\n");
    printf("Stack:    No canary found\n");
    printf("NX:       NX unknown - GNU_STACK missing\n");
    printf("PIE:      No PIE\n");
    printf("Stack:    Executable\n");
    printf("RWX:      Has RWX segments\n\n");
}

void print_menu()
{
    printf("Armory Management System\n");
    printf("<Menu>\n");
    printf("[0] Turn Off Armory Management System\n");
    printf("[1] Power Supply\n");
    printf("[2] Power cut-off\n");
    printf("[3] Weapon Select\n");
    printf("[4] Check the security system log\n");
    printf("[5] Open Door\n");
    printf("[6] Close Door\n\n");
}

int main(void)
{
    int select_menu;

    print_menu();
    
    while(1)
    {
        printf("Select Menu : ");
        scanf("%d", &select_menu);
        
        if(select_menu == 0)
        {
            break;
        }
        else if(select_menu == 1)
        {
            Power_Supply();
        }
        else if(select_menu == 2)
        {
            Power_cut_off();
        }
        else if(select_menu == 3)
        {
            Weapon_Select();
        }
        else if(select_menu == 4)
        {
            Check_Security_System_Log();
        }
        else if(select_menu == 5)
        {
            Open_Door();
            puts(" ");
        }
        else if(select_menu == 6)
        {
            Close_Door();
        }
        else
        {
            printf("Wrong input!\n");
            break;
        }
    }
}
