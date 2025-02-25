//gcc -o prob prob.c -fstack-protector -no-pie
#include <stdio.h>

void menu(){
    puts("1. read diary");
    puts("2. write diary");
    puts("3. put down the diary");
    printf("> ");
}

int main(){
    setbuf(stdin, 0);
    setbuf(stdout, 0);
    int ch, index = 0;
    char page1[] = "As soon as I arrived here, I locked the door tightly.\nCatching my breath, it feels like a miracle that I managed to escape safely.";
    char page2[] = "Looking around, there isn't much food left.\nTo survive, I'll have to go out again soon.";
    char page3[] = "I checked my weapons and packed the necessary supplies in my bag.\nAccording to rumors I heard outside, there's a vaccine at a nearby lab.";
    char page4[] = "As I headed out, I could hear the zombies' cries.\nMy heart was pounding wildly, but I moved quietly.";
    char page5[] = "At that moment, a zombie suddenly attacked me.\nAs I checked the bite wound on my arm, I realized that the vaccine at the lab was now my last hope.";
    char hidden[] = "Failed, failed, failed, failed, failed, faile... itchy, tasty";
    char* diary[] = {page1, page2, page3, page4, page5, hidden};\
    puts("");
    printf("  ██████  █    ██  ██▀███   ██▒   █▓ ██▓ ██▒   █▓ ▒█████   ██▀███    ██████    ▓█████▄  ██▓ ▄▄▄       ██▀███ ▓██   ██▓\n");
    printf("▒██    ▒  ██  ▓██▒▓██ ▒ ██▒▓██░   █▒▓██▒▓██░   █▒▒██▒  ██▒▓██ ▒ ██▒▒██    ▒    ▒██▀ ██▌▓██▒▒████▄    ▓██ ▒ ██▒▒██  ██▒\n");
    printf("░ ▓██▄   ▓██  ▒██░▓██ ░▄█ ▒ ▓██  █▒░▒██▒ ▓██  █▒░▒██░  ██▒▓██ ░▄█ ▒░ ▓██▄      ░██   █▌▒██▒▒██  ▀█▄  ▓██ ░▄█ ▒ ▒██ ██░\n");
    printf("  ▒   ██▒▓▓█  ░██░▒██▀▀█▄    ▒██ █░░░██░  ▒██ █░░▒██   ██░▒██▀▀█▄    ▒   ██▒   ░▓█▄   ▌░██░░██▄▄▄▄██ ▒██▀▀█▄   ░ ▐██▓░\n");
    printf("▒██████▒▒▒▒█████▓ ░██▓ ▒██▒   ▒▀█░  ░██░   ▒▀█░  ░ ████▓▒░░██▓ ▒██▒▒██████▒▒   ░▒████▓ ░██░ ▓█   ▓██▒░██▓ ▒██▒ ░ ██▒▓░\n");
    printf("▒ ▒▓▒ ▒ ░░▒▓▒ ▒ ▒ ░ ▒▓ ░▒▓░   ░ ▐░  ░▓     ░ ▐░  ░ ▒░▒░▒░ ░ ▒▓ ░▒▓░▒ ▒▓▒ ▒ ░    ▒▒▓  ▒ ░▓   ▒▒   ▓▒█░░ ▒▓ ░▒▓░  ██▒▒▒\n");
    printf("░ ░▒  ░ ░░░▒░ ░ ░   ░▒ ░ ▒░   ░ ░░   ▒ ░   ░ ░░    ░ ▒ ▒░   ░▒ ░ ▒░░ ░▒  ░ ░    ░ ▒  ▒  ▒ ░  ▒   ▒▒ ░  ░▒ ░ ▒░▓██ ░▒░\n");
    printf("░  ░  ░   ░░░ ░ ░   ░░   ░      ░░   ▒ ░     ░░  ░ ░ ░ ▒    ░░   ░ ░  ░  ░      ░ ░  ░  ▒ ░  ░   ▒     ░░   ░ ▒ ▒ ░░\n\n");

    while(1){
        menu();
        scanf("%d", &ch);
        if (ch == 1){
            printf("index (0~4) : ");
            scanf("%d", &index);
            if (index >= 6 || index < 0){
                puts("invalid index");
                continue;
            }
            puts(diary[index]);
        }
        else if (ch == 2){
            printf("index (0~4) : ");
            scanf("%d", &index);
            if (index >= 6 || index < 0){
                puts("invalid index");
                continue;
            }
            printf("content > ");
            read(0, diary[index], 0x100);
        }
        else if (ch == 3){
            break;
        }
    }
    puts("Ok let's go!");
    return 0;
}