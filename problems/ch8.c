#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void open_emergency_medicine(){
	char buf[30];
	int fd = open("flag" , O_RDONLY);
	read(fd,buf,20);
	printf("%s\n",buf);
	close(fd);
}

void empty(){
	printf("There is no more medicine\n");
}
void exist(){
	printf("This medicine is located in the .fsb section.\n");
}

void init(){
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
}

void menu(){
	puts("1. search medicine");
	puts("2. take medicine");
	puts("3. quit");
	printf("> ");
}

int main(){
	init();
	int *exitst_or_not=(int *)exist;
	char buf[0x100];
	int num;
	puts("Welcome to BOF pharmacy");
	puts("What do you want?");
	while(1){
		menu();
		scanf("%d",&num);
		switch(num){
			case 1:
				memset(buf,0,0x100);
				read(0, buf, 0x9f);
				printf(buf);
				if(strstr(buf, "Painkiller") || strstr(buf, "Morphine") || strstr(buf, "ibuprofen")){
					exitst_or_not = (int *)empty;
				}
				break;
			case 2:
				if(exitst_or_not != NULL){
					(*(void (*)()) exitst_or_not)();
				}
				else{
					printf("Choose medicine first\n");
				}
				break;
			case 3:
				printf("Goodbye\n");
				return 0;
				break;
			default:
				printf("Wrong input\n");
				break;
		}
		
	}
	return 0;

	
}
