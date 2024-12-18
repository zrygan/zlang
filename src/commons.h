/**
 * Author:  Zhean Robby Ganituen
 * Date:    December 19, 2024
 * Project: zlang Programming Language
 * 
 * Contains the primary functions and interpreter tools, helper functions, and variables.
 */

#ifndef COMMONS
#define COMMONS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __STRING_LEN__ 256 * sizeof(char)
#define __MAX_TOKS__ 2048

char *__FILE_NAME__;
char **__TOKS__;
int __TOKS_COUNT__;

typedef char** __VARS__[4096]; // FIXME: change to double pointer ** (?)

#endif