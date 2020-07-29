#include <stdio.h> 
#include <stdlib.h>
#include "../Header/copy.h"

#define BUFFER_SIZE 64

int copy(char *source, char *target) {
    FILE *source_file, *target_file, *check_file;
    if((source_file = fopen(source, "r")) == NULL){
        printf("\nSorry, There is no such file : %s", source);
        return -2;
    }
    if(!((check_file = fopen(target, "r")) == NULL)) {
        printf("\nSorry, the file already exists : %s", target);
        fclose(check_file);
        return -2;
    }
    target_file = fopen(target, "w");
    char *buffer = (char*) malloc(BUFFER_SIZE);
    int read_size;
    while((read_size = fread(buffer, BUFFER_SIZE, 1, source_file)) > 0) {
        // fwrite(buffer, BUFFER_SIZE, 1, target_file);
        fputs(buffer, target_file);
    }
    free(buffer);
    fclose(source_file);
    fclose(target_file);
    return 1;
}
