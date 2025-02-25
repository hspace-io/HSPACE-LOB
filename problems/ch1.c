#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

char id[] = "helloworld";
char pw[] = "plzboft0s0lv3ch4ll";
char flag[] = "w3lcom3_to_pwn4ble_w0r1d";

void flag_finder()
{  
    FILE * fp;

    fp = fopen(".TOP_SECRET", "r");

    char data[20] = {0, };

    fread(data, sizeof(char), 19, fp);

    fclose(fp);
    fp = NULL;

    printf("%s\n\n", data);

    printf("Press enter to exit\n");
    getchar();
    getchar();
}

void ascii()
{
    printf("\n");
    printf("   ▄████████ ████████▄    ▄▄▄▄███▄▄▄▄    ▄█  ███▄▄▄▄   \n");
    printf("  ███    ███ ███   ▀███ ▄██▀▀▀███▀▀▀██▄ ███  ███▀▀▀██▄ \n");
    printf("  ███    ███ ███    ███ ███   ███   ███ ███▌ ███   ███ \n");
    printf("  ███    ███ ███    ███ ███   ███   ███ ███▌ ███   ███ \n");
    printf("▀███████████ ███    ███ ███   ███   ███ ███▌ ███   ███ \n");
    printf("  ███    ███ ███    ███ ███   ███   ███ ███  ███   ███ \n");
    printf("  ███    ███ ███   ▄███ ███   ███   ███ ███  ███   ███ \n");
    printf("  ███    █▀  ████████▀   ▀█   ███   █▀  █▀    ▀█   █▀  \n");
    printf("                                                       \n");
    printf("\n");
}

void user_ascii()
{
    printf("\n");
    printf("███    █▄     ▄████████    ▄████████    ▄████████ \n");
    printf("███    ███   ███    ███   ███    ███   ███    ███ \n");
    printf("███    ███   ███    █▀    ███    █▀    ███    ███ \n");
    printf("███    ███   ███         ▄███▄▄▄      ▄███▄▄▄▄██▀ \n");
    printf("███    ███ ▀███████████ ▀▀███▀▀▀     ▀▀███▀▀▀▀▀   \n");
    printf("███    ███          ███   ███    █▄  ▀███████████ \n");
    printf("███    ███    ▄█    ███   ███    ███   ███    ███ \n");
    printf("████████▀   ▄████████▀    ██████████   ███    ███ \n");
    printf("                                       ███    ███ \n");
    printf("\n");
}

void file_read(char * path){//make path
    int len = 0;
    char * data;

    FILE * fp;
    fp = fopen(path, "r");
    
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    rewind(fp);

    data = (char*)malloc(sizeof(char) * len);

    if(data == NULL){
	printf("allocate Error\n");
	exit(0);
    }

    fread(data, sizeof(char), len, fp);
    printf("%s\n\n", data);

    free(data);
    data = NULL;

    printf("Press enter to exit\n");
    getchar();
    getchar();

}

void root()
{
    int res;
    while(true){
        system("clear");
        ascii();
        printf("User: admin\n");
        printf("\n");
        printf("1. S/W Info\n");
        printf("2. Check File\n");
        printf("3. Exit\n");

        printf("\n");
        printf("Select Menu: ");
        scanf("%d", &res);

        switch (res)
        {
        case 1:
            system("clear");
            printf("File Viewer\n");
            printf("Version: 3.0.2\n\n");

	    printf("Press enter to exit\n");
	    getchar();
	    getchar();
            break;
        
        case 2:
            system("clear");
	    //flag_finder();
	    file_read((char*)".TOP_SECRET");
            break;

        case 3:
            system("clear");
            printf("Goodbye\n");
            exit(0);
            break;

        default:
            printf("Invalid Number\n");
            exit(0);
        }
    }
}

void menu()
{
    int res;

    while (true){
        system("clear");
        user_ascii();
        printf("1. S/W Info\n");
        printf("2. Check File\n");
        printf("3. Exit\n");

        printf("Select Menu: ");
        scanf("%d", &res);

        switch (res)
        {
        case 1:
            system("clear");
            printf("File Viewer\n");
            printf("Version: 3.0.2\n");
            printf("Press enter to exit\n\n");
            getchar();
	    getchar();
            break;
        case 2:
            system("clear");
	    file_read((char*)".SECRET");
            break;

        case 3:
            system("clear");
            printf("Goodbye\n");
            exit(0);
            break;

        default:
            printf("Invalid Number\n");
            break;
        }
    }
    
}

int main()
{
    int cmp1 = 3, cmp2 = 3, cmp3 = 3, cmp4 = 3;
    char admin[10] = "deny", id_input[20], pw_input[20];

    system("clear");

    printf("ID: ");
    scanf("%s", id_input);
    printf("PASSWORD: ");
    scanf("%s", pw_input);
    sleep(1);
    if(strncmp(id_input, "admin", 5) == 0) printf("%s\n", admin);
    sleep(1);

    cmp1 = strncmp(id, id_input, 10);
    cmp2 = strncmp(pw, pw_input, 19);
    cmp3 = strncmp(id_input, "admin", 5);
    cmp4 = strncmp(admin, "confirm", 7);

    if(cmp1 == 0 && cmp2 == 0){
        printf("Wellcome Back!\n");
        menu();
        exit(0);
    }

    if(cmp3 == 0 && cmp4 == 0){
	system("clear");
        printf("Redirect to Admin page\n");

        sleep(1);
        printf(".......\n");
        sleep(1);
        printf(".......\n");
        sleep(1);
        printf(".......\n");
        sleep(1);
        printf(".......\n");
        sleep(1);
        printf(".......\n");

        system("clear");

        root();

        exit(0);
    }
    

    return 0;
}


