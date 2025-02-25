#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

// Bunker status structure
typedef struct {
    int power;
    int doors;
    int IPS;
    char airQuality[10];
    char waterSupply[10];
    char communication[10];
    char structuralIntegrity[10];
} BunkerStatus;

struct auth {
    char username[50];
    char passwd[50];
};

void generateRandomCode(char *code, int length) {
    int fd;
    char randByte;

    if ((fd = open("/dev/random", O_RDONLY)) == -1)
    {
        perror("open error");
        exit(1);
    }
    if ((read(fd, code, length)) == -1)
    {
        perror("read error");
        exit(1);
    }

    for (int i = 0; i < length; i++) {
        randByte = code[i] % 10;
        if ((randByte) < 0)
            randByte += 10;
             
        code[i] = '0' + randByte; // Generate random digit
    }

}

void printStatus(BunkerStatus *status) {
    printf("Bunker Status:\n");
    printf("- Power: %s\n", status->power ? "ON" : "OFF");
    printf("- Doors: %s\n", status->doors ? "OPEN" : "CLOSED");
    printf("- IPS Systems: %s\n", status->IPS ? "ACTIVATED" : "DEACTIVATED");
    printf("- Air Quality: %s\n", status->airQuality);
    printf("- Water Supply: %s\n", status->waterSupply);
    printf("- Communication Systems: %s\n", status->communication);
    printf("- Structural Integrity: %s\n", status->structuralIntegrity);
}

void lockdown(BunkerStatus *status) {
    printf("Initiating lockdown procedure...\n");
    status->doors = 0;
    status->IPS = 1;
    status->power = 1;
    printf("Lockdown in progress...\n");
    printf("All doors closed. IPS systems activated. Power supply secured.\n");
}

void openDoors(BunkerStatus *status) {
    printf("Opening all bunker doors...\n");
    status->doors = 1;
    printf("Doors are now OPEN.\n");
}

void closeDoors(BunkerStatus *status) {
    printf("Closing all bunker doors...\n");
    status->doors = 0;
    printf("Doors are now CLOSED.\n");
}

void activateIPS(BunkerStatus *status) {
    printf("Activating IPS systems...\n");
    status->IPS = 1;
    status->doors = 0;
    printf("IPS systems are now ACTIVATED.\n");
}

void deactivateIPS(BunkerStatus *status) {
    printf("Deactivating IPS systems...\n");
    status->IPS = 0;
    status->doors = 1;
    printf("IPS systems are now DEACTIVATED.\n");
    openDoors(&status);
}

void powerOn(BunkerStatus *status) {
    printf("Powering on the bunker...\n");
    status->power = 1;
    printf("Power is now ON.\n");
}

void powerOff(BunkerStatus *status) {
    printf("Powering off the bunker...\n");
    status->power = 0;
    printf("Power is now OFF.\n");
}

void performSystemCheck(BunkerStatus *status) {
    printf("Performing system diagnostic check...\n");
    printStatus(status);
}

void displayHelp() {
    printf("Available commands:\n");
    printf("- status           : Display the current status of the bunker.\n");
    printf("- lockdown         : Initiate lockdown procedure.\n");
    printf("- open_doors       : Open all bunker doors.\n");
    printf("- close_doors      : Close all bunker doors.\n");
    printf("- activate_IPS     : Activate IPS systems.\n");
    printf("- deactivate_IPS   : Deactivate IPS systems.\n");
    printf("- power_on         : Turn on the power.\n");
    printf("- power_off        : Turn off the power.\n");
    printf("- system_check     : Perform a system diagnostic check.\n");
    printf("- exit             : Exit the Bunker Control System.\n");
}

int IPS() {
    char username[50];
    char passwd[50];

    int accessGranted = 0;
    int count = 0;

    struct auth *auth = malloc(sizeof(struct auth));

    strcpy(auth->username, "admin");
    generateRandomCode(auth->passwd, 50);

    printf("\nIntrusion Prevention System Active.\n");
    printf("Authenticate to access the system\n\n");

    while (!accessGranted && count < 3) {
        printf("Username: ");
        read(0, username, sizeof(struct auth));
        //fgets(username, sizeof(auth), stdin);
        username[strcspn(username, "\n")] = '\0';

        printf("Password: ");
        read(0, passwd, sizeof(struct auth));
        //fgets(passwd, sizeof(auth), stdin);
        passwd[strcspn(passwd, "\n")] = '\0';


        printf("\nYour account: %s\n", username); 
        if (!strncmp(passwd, auth->passwd, sizeof(auth)) && !strncmp(username, auth->username, sizeof(auth))) {
            accessGranted = 1;
            printf("Access granted.\n");
            return 0 ;
        } else {
            printf("Incorrect code. Try again.\n");
            count++;
        }
    }
    printf("3 incorrect code attempts\n");
    for (int i = 30; i > 0; i--){
        printf("%d Second left\r", i);
        sleep(1);
    }
    return -1;
}

void init() {
  setvbuf(stdin, 0, 2, 0);
  setvbuf(stdout, 0, 2, 0);
}

int main() {
    init();

    do{

        printf("##############################################################\n");
        printf("#                    Bunker Control System                   #\n");
        printf("##############################################################\n");
        printf("Welcome to the Bunker Control System (BCS).\n");
        printf("Please enter a command. Type 'help' for a list of available commands.\n");

    }while(IPS());

    char command[50];
    BunkerStatus status = {1, 0, 1, "GOOD", "NORMAL", "FUNCTIONAL", "SOUND"};

    while (1) {
        printf("\n> ");
        fgets(command, 50, stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "help") == 0) {
            displayHelp();
        } else if (strcmp(command, "status") == 0) {
            printStatus(&status);
        } else if (strcmp(command, "lockdown") == 0) {
            lockdown(&status);
        } else if (strcmp(command, "open_doors") == 0) {
            openDoors(&status);
        } else if (strcmp(command, "close_doors") == 0) {
            closeDoors(&status);
        } else if (strcmp(command, "activate_IPS") == 0) {
            activateIPS(&status);
        } else if (strcmp(command, "deactivate_IPS") == 0) {
            deactivateIPS(&status);
        } else if (strcmp(command, "power_on") == 0) {
            powerOn(&status);
        } else if (strcmp(command, "power_off") == 0) {
            powerOff(&status);
        } else if (strcmp(command, "system_check") == 0) {
            performSystemCheck(&status);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the Bunker Control System...\n");
            break;
        } else {
            printf("Unknown command. Type 'help' for a list of available commands.\n");
        }
    }

    return 0;
}
