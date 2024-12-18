#ifndef HASH_W
#define HASH_W

#ifdef __cplusplus
extern "C"{
#endif

void* __HASH_VARIABLES_MAKE__();
void __HASH_VARIABLES_DELETE__(void *hash);
void __HASH_VARIABLES_PUT__(void *hash, const char *key, int value);
int __HASH_VARIABLES_GET__(void *hash, const char *key);

#ifdef __cplusplus
}
#endif

#endif