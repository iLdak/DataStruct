#ifndef _HASH_H_
#define _HASH_H_

typedef void Hash;
typedef void HashKey;
typedef void HashValue;

typedef int (compared_HashKey)(HashKey*, HashKey*);

Hash* Hash_Create();

void Hash_Destroy(Hash* hash);

void Hash_Clear(Hash* hash);

int Hash_Add(Hash* hash, HashKey* key, HashValue* value, compared_HashKey* compared);

HashValue* Hash_Remove (Hash* hash, HashKey* key, compared_HashKey* compared);

HashValue* Hash_Get(Hash* hash,HashKey* key, compared_HashKey* compared);

int Hash_Count(Hash* hash);

#endif
