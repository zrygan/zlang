#ifndef MAIN
#define MAIN

#include <stdlib.h>

typedef char String[255];

const int __MAX_TOKS__ = 4096;
String __FILE_NAME__;
char **__TOKS__;
typedef String __VARS__[4096]; // FIXME: change to double pointer ** (?)

#endif