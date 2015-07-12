#include "BSTree.h"
#include "Hash.h"
#include <stdio.h>
#include <malloc.h>

typedef struct _tag_HashNode HashNode;
struct _tag_HashNode
{
	BSTreeNode header;
	HashValue* value;
};

static void Clear_Recursive(HashNode* node)
{
	if(node != NULL)
	{
		Clear_Recursive(node->header.left);
		
		Clear_Recursive(node->header.right);
		
		free(node);
	}
}

Hash* Hash_Create()
{
	return BSTree_Create();
}

void Hash_Destroy(Hash* hash)
{
	Hash_Clear( hash );
	
	free( hash );
}

void Hash_Clear(Hash* hash)
{
	Clear_Recursive( BSTree_Root(hash) );
	
	BSTree_Clear( hash );
}

int Hash_Add(Hash* hash, HashKey* key, HashValue* value, compared_HashKey* compared)
{
	HashNode* node = (HashNode*)malloc(sizeof(HashNode));
	
	int ret;
	
	if( ret = (node != NULL) )
	{
		node->header.key = key;
		node->value = value;
		
		ret = BSTree_Insert(hash, node, compared);
		
		if(ret != 1)
		{
			free(node);
		}
	}

	return ret;
}

HashValue* Hash_Remove (Hash* hash, HashKey* key, compared_HashKey* compared)
{
	HashNode* node = NULL;
	
	HashValue* ret;

	node = BSTree_Delete(hash, key, compared);

	if(node != NULL)
	{
		ret = node->value;
		
		free(node);
	}
	
	return ret;
}

HashValue*Hash_Get(Hash* hash,HashKey* key, compared_HashKey* compared)
{
	HashNode* node = NULL;
	
	HashValue* ret;
	
	node = BSTree_Get(hash, key, compared);
	
	if(node != NULL)
	{
		ret = node->value;
	}
	
	return ret;
}

int Hash_Count(Hash* hash)
{
	return BSTree_Count(hash);
}
