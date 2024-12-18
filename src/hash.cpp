/**
 * Author:  Zhean Robby Ganituen
 * Date:    December 19, 2024
 * Project: zlang Programming Language
 * 
 * Contains the hash for variables, function names, etc.
 */

#include "hash_w.h"
#include <string>
#include <unordered_map>

using namespace std;

class __HASH_VARIABLES__{
    public:
        unordered_map<string, long long> map;

        void put(const string &key, long long value){
            map[key] = value;
        }

        int get(const string &key){
            auto it = map.find(key);
            return it != map.end() ? it->second : -1;
        }
};

void* __HASH_VARIABLES_MAKE__() {
    return new __HASH_VARIABLES__(); 
}

void __HASH_VARIABLES_DELETE__(void* hash){
    delete static_cast<__HASH_VARIABLES__*>(hash);
}

void __HASH_VARIABLES_PUT__(void *hash, const char *key, long long value){
    static_cast<__HASH_VARIABLES__*>(hash)->put(key, value);
}

long long __HASH_VARIABLES_GET__(void *hash, const char *key){
    return static_cast<__HASH_VARIABLES__*>(hash)->get(key);
}