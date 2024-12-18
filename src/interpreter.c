/**
 * Author:  Zhean Robby Ganituen
 * Date:    December 19, 2024
 * Project: zlang Programming Language
 * 
 * Contains the base interpreter.
 */

#include "interpreter.h"
#include "hash_w.h"
#include "commons.h"

char *__KEYS__[] = {"{",
                    "}",
                    "(",
                    ")",
                    ",",

                    // FIXME: add syntax for comment here
                    // data types
                    "int",      // integer
                    "flt",      // float
                    "str",      // string
                    "chr",      // char
                    "bool",     // boolean
                    
                    // variable declaration and assignment
                    "=",        // assign to
                    "+=",       // increment assignemnt
                    "-=",       // decrement assignment
                    "*=",       // multiply assignment
                    "/=",       // divide assignment
                    "%%=",      // modulo assignment (%=)
                    
                    // arithmentic operators
                    "+",        // add
                    "-",        // minus
                    "*",        // times
                    "/",        // divide
                    "%%",       // modulo
                    "^",        // exponent

                    // comparison operators
                    "<",        // less
                    ">",        // greater
                    ">=",       // greater or equal
                    "<=",       // less or equal
                    "==",       // equal
                    "!="        // not equal
                
                    // conditionals (if)
                    "if",
                    "elif",
                    "else",

                    // conditionals (switch-case)
                    "switch",
                    "case",

                    // loops (for-loop)
                    "for",
                    "to",
                    "by",
                    "in",
                    "at",
                    "continue",
                    "break",

                    // loops (while)
                    "while",
                    "dowhile"
};

void EXECUTE_BASE(void* __HASH_VARIABLE__){
    char *curr = malloc(__STRING_LEN__);
    for (int i = 0; i < __TOKS_COUNT__; i++){
        strcpy(curr, __TOKS__[i]);

        if (strcmp("int", curr) == 0){
            char *var = malloc(__STRING_LEN__);
            i++; 
            strcpy(var, __TOKS__[i]);

            if (__HASH_VARIABLES_GET__(__HASH_VARIABLE__, var) != -1){
                printf("<< zlang >> Error 3. Variable declaration error at token %d, variable %s redeclared.\n", i, var);
            } else {
                i++;
                char *operator = __TOKS__[i];
                if (strcmp("=", operator) == 0){
                    i++;
                    char *endptr;
                    long long value = strtol(__TOKS__[i], &endptr, 10);

                    __HASH_VARIABLES_PUT__(__HASH_VARIABLE__, var, value);
                } else{
                    printf("<< zlang >> Error 4. Expected assignment operator (=) on token %d, given %s.\n", i + 1, operator);
                }
            }
            free(var);
        }
    }

    free(curr);
    printf("%lld\n", __HASH_VARIABLES_GET__(__HASH_VARIABLE__, "x"));
}