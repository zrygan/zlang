/**
 * Author:  Zhean Robby Ganituen
 * Date:    December 19, 2024
 * Project: zlang Programming Language
 * 
 * Contains the hash for variables, function names, etc.
 * Wrapper for the C++ class.
 */

#ifndef HASH_W
#define HASH_W

#ifdef __cplusplus
extern "C"{
#endif

void* __HASH_VARIABLES_MAKE__();
void __HASH_VARIABLES_DELETE__(void *hash);
void __HASH_VARIABLES_PUT__(void *hash, const char *key, long long value);
long long __HASH_VARIABLES_GET__(void *hash, const char *key);

#ifdef __cplusplus
}
#endif

#endif