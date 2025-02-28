#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

int cmp = 0xfffff, num = 0;
char srl[30] = "3t267s77wh2djfi3mid2od2o329dw";

void dec(char * ptr, int len)
{
    for(int i = 0; i < len; i++){
        ptr[i] ^= 0x40;       
    }
}

void print_file()
{
    FILE * fp;
    int flsz = 0;
    char * file = 0;

    printf("Wait until decode\n");

    sleep(3);

    fp = fopen(".Real_Top_Secret", "rb");

    fseek(fp, 0, SEEK_END);
    flsz = ftell(fp);
    rewind(fp);

    file = malloc(sizeof(char)*flsz+1);
    memset(file, 0, flsz+1);

    fread(file, flsz, 1, fp);

    dec(file, flsz);

    system("clear");

    printf("--------------------------------------------------------------------------\n");
    printf("%s\n", file);
    printf("--------------------------------------------------------------------------\n");

    fclose(fp);
    free(file);
    file = NULL;

    if(getchar() != 0){
        system("clear");
    }

    free(file);
    file = NULL;
}


int main()
{
    char serial[256] = {0, };

    printf("Serial Number: ");
    gets(serial);

    if(strlen(serial) == 29){
        cmp = strcmp(serial, srl);
        if(cmp == 0){
            printf("Welcome Back!\n");
            print_file();
            goto end;
        }
    }

    end:
    return 0;
}
