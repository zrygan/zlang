#include "main.h"
#include "hash_w.h"
#include <stdio.h>
#include <string.h>

void READER(){
    FILE* file;
    String buffer;
    int c = 0;
    file = fopen(__FILE_NAME__, "r");
    if (file == NULL){
        printf("<< zlang>> Error DNE: File does not exist.\nFile name: %s.\n", __FILE_NAME__);
        exit(0);
    }

    __TOKS__ = malloc(__MAX_TOKS__ * sizeof(char*));
    if (__TOKS__ == NULL){
        perror("<< c >> __TOKS__ Error: Memory allocation failed. Error 1.\n");
        fclose(file);
        exit(0);
    }
    
    while (fscanf(file, "%s", buffer) != EOF){
        __TOKS__[c] = malloc(strlen(buffer) + 1);
        if (__TOKS__[c] == NULL){
            perror("<< c >> __TOKS__ Error: Memory allocation failed. Error 2.\n");
        }  
        
        strcpy(__TOKS__[c], buffer);
        c++;

        if (c >= (int) __MAX_TOKS__){
           printf("<< zlang >> Error 2. Reached maximum interpretable source code length. __MAX_TOKS__: %d.\n", __MAX_TOKS__);
        }
    }

    fclose(file);
}

int main(){ 
    fgets(__FILE_NAME__, sizeof(__FILE_NAME__), stdin);
    __FILE_NAME__[strcspn(__FILE_NAME__, "\n")] = '\0'; 


    char ext[6];
    strncpy(ext, &__FILE_NAME__[strlen(__FILE_NAME__) - 5], 5);
    ext[5] = '\0';

    if (strcmp(ext,".zerg") == 0) READER();
    else printf("<< zlang >> Error 1: Wrong file type.\nFile type: %s.\n", ext);
}