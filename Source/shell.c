#include <stdio.h> //컴파일러가 2번 스캔(선언부, 구현부)해야 될 것을 따로 빼놓는 것. 선언부를 따로 빼놓음. extern -> 다이나믹 링크. 별도의 외부 오브젝트를 가져오라고.
#include <stdlib.h>
#include <string.h>
#include "../Header/copy.h"

#define COMM_COPY "copy"
#define COMM_QUIT "quit"

int command_center(char *command_input) {
    char command[100];
    char *command_ptr;
    char *params[100];
    
    strcpy(command, command_input);
    command[strlen(command) - 1] = '\0'; // new line character -> end of line
    command_ptr = strtok(command, " ");

    if (strcmp(command_ptr, COMM_QUIT) == 0) {
        return 0;
    } else if (strcmp(command_ptr, COMM_COPY) == 0) {
        int count = 0;
        while((command_ptr = strtok(NULL, " ")) != NULL) {
            params[count] = command_ptr; 
            count += 1;
        }

        if (count == 2) {
            printf("\nCopying %s, and paste it into %s",params[0], params[1]);
            int copy_result = copy(params[0], params[1]);
            return copy_result;
        } else {
            printf("\nThere must be 2 parameters (source file and target file).");
            return -2;
        }

        return 1;
    } else {
        return -1;
    }
    return 1;
}

int main() {
    int center_signal;
    char command[100];

    while(1) {
        printf("\ncommand :");
        fgets(command, 100, stdin);

        center_signal = command_center(command);
        switch(center_signal){
            case 1:
                printf("\nI've done your task!");
                break;
            case 0:
                printf("\nTerminating shell, Thank you!\n");
                return 0;
            case -1:
                printf("\nCommand Not Found");
                break;
            case -2:
                printf("\nPlease, retry!");
                break;
        }
    }
    return 0;
}