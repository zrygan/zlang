/**
 * Author:  Zhean Robby Ganituen
 * Date:    December 19, 2024
 * Project: zlang Programming Language
 * 
 * Contains the main function and interpreter tools, helper functions, and variables.
 */

#include "commons.h"
#include "hash_w.h"
#include "interpreter.h"

int READER(){
    FILE *file;
    char *buffer = malloc(__STRING_LEN__);
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
    free(buffer);
    
    return c;
}

int main(){
    __FILE_NAME__ = malloc(__STRING_LEN__);
    fgets(__FILE_NAME__, 256, stdin);
    __FILE_NAME__[strcspn(__FILE_NAME__, "\n")] = '\0'; 

    char ext[6];
    strncpy(ext, &__FILE_NAME__[strlen(__FILE_NAME__) - 5], 5);
    ext[5] = '\0';

    if (strcmp(ext,".zerg") == 0) __TOKS_COUNT__ = READER();
    else printf("<< zlang >> Error 1: Wrong file type.\nFile type: %s.\n", ext);

    free(__FILE_NAME__);

    void* __HASH_VARIABLE__ = __HASH_VARIABLES_MAKE__();
    EXECUTE_BASE(__HASH_VARIABLE__);

    return 0;
}