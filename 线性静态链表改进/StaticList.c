#include <stdio.h>
#include <malloc.h>
#include "StaticList.h"

#define AVIALIBLE -1

typedef struct _tag_StaticListNode
{
	unsigned int data;
	int next;
}TStaticListNode;

typedef struct _tag_StaticFreeList
{
	int length;  //空闲的个数
	TStaticListNode freeHeader;
	TStaticListNode free[]; 
}TStaticFreeList;

typedef struct _tag_StaticList
{
	int capacity;
	TStaticListNode header;
	int freeList;
	TStaticListNode node[];
}TStaticList;


StaticList* StaticList_Create(int capacity1)
{
	TStaticList* ret = NULL;
	int i = 0;
	TStaticFreeList* TStaticFreeListLocal = NULL;
	
	printf("Create Static List ...\n");
	
	if(capacity1 >= 0)
	{
		ret = (TStaticList*)malloc(sizeof(TStaticList) + (sizeof(TStaticListNode) * (capacity1 + 1)));
		ret->freeList = (TStaticFreeList*)malloc(sizeof(TStaticFreeList) + sizeof(TStaticListNode) * (capacity1 + 1));
		
		TStaticFreeListLocal = (TStaticFreeList*)ret->freeList;
	}
		
	if(ret != NULL)
	{
		ret->capacity = capacity1;
		ret->header.data = 0;
		ret->header.next = 0;
		for(i = 1; i <= ret->capacity; i++)
		{
			ret->node[i].next = AVIALIBLE;
			TStaticFreeListLocal->free[i].data = i;
			TStaticFreeListLocal->free[i].next = i + 1;
		}
		TStaticFreeListLocal->free[i].next = NULL;
		TStaticFreeListLocal->length = capacity1 - 1;
		TStaticFreeListLocal->freeHeader = TStaticFreeListLocal->free[1];
	}
		
	return ret;
}

void StaticList_Destroy(StaticList* list)
{
	TStaticList* slist = (TStaticList*) list;
	TStaticFreeList* TStaticFreeListLocal = (TStaticFreeList*)slist->freeList;
	
	printf("Destroy Static List ...\n");
	
	free(TStaticFreeListLocal);
	free(slist);	
}

void StaticList_Clear(StaticList* list)
{
	TStaticList* slist = (TStaticList*) list;
	TStaticFreeList* TStaticFreeListLocal = (TStaticFreeList*)slist->freeList;
	int i = 0;
	
	if(slist != NULL)
	{
		slist->header.data = 0;
		slist->header.next = 0;
		
		for(i = 1; i <= slist->capacity; i++)
		{
			slist->node[i].next = AVIALIBLE;
			TStaticFreeListLocal->free[i].data = i;
			TStaticFreeListLocal->free[i].next = i + 1;
		}
		
		TStaticFreeListLocal->free[i].next = NULL;
		TStaticFreeListLocal->length = slist->capacity - 1;
		TStaticFreeListLocal->freeHeader = TStaticFreeListLocal->free[1];
	}
}

int StaticList_Length(StaticList* list)
{
	TStaticList* slist = (TStaticList*) list;
	int ret;
	
	if(slist != NULL)
	{	
		ret = slist->header.data;
	}
	
	return ret;
}

int StaticList_Capacity(StaticList* list)
{
	TStaticList* slist = (TStaticList*) list;
	int ret = -1;

	if(slist != NULL)
	{	
		ret = slist->capacity;
	}

	return ret;
}

int StaticList_Insert(StaticList* list, StaticListNode* node, int pos)
{
	TStaticList* slist = (TStaticList*) list;
	TStaticFreeList* TStaticFreeListLocal = (TStaticFreeList*)slist->freeList;
	
	int i = 0;
	int index = 0;
	int cunt = 0;
	
	int ret = (slist != NULL);
	ret = ret && (0 <= pos) && (pos <= slist->capacity);
	ret = ret && (slist->capacity > slist->header.data);
	
	unsigned int freeLen = TStaticFreeListLocal->length;//剩余个数 
	int tic = TStaticFreeListLocal->freeHeader.data;
	unsigned int nextTic = TStaticFreeListLocal->freeHeader.next; 
	
	if(ret && freeLen)
	{
 		slist->node[tic].data = (unsigned int)node;//保存数据 
		
		slist->node[cunt] = slist->header;
		for(i = 0; (i < pos) && (slist->node[cunt].next != 0); i++)
		{
			cunt = slist->node[cunt].next;
		}
		
		slist->node[tic].next = slist->node[cunt].next;
		
		slist->node[cunt].next = tic;
		
		slist->node[0].data++;
		
		slist->header = slist->node[0];	
		
		freeLen--;
		TStaticFreeListLocal->length = freeLen;
		if(0 == freeLen)
		{
			TStaticFreeListLocal->freeHeader.data = NULL;
			TStaticFreeListLocal->freeHeader.next = NULL; 
		}
		else
		{
			TStaticFreeListLocal->freeHeader = TStaticFreeListLocal->free[nextTic];//指向下一个空闲的数组成员 
		}
		
		
	}
	return ret;
}

StaticListNode* StaticList_Get(StaticList* list, int pos)
{
	TStaticList* slist = (TStaticList*) list;
	
	TStaticListNode* ret = NULL;
	
	int cunt = 0;
	int i = 0;
	int object = 0;
	
	if(slist != NULL && (0 <= pos) && (pos < slist->header.data))
	{
		slist->node[cunt] = slist->header;
		
		for(i = 0; i < pos; i++)
		{
			cunt = slist->node[cunt].next;
		}
		
		object = slist->node[cunt].next;
		ret = (TStaticListNode*)slist->node[object].data;
	}
	
	return ret;
}

StaticListNode* StaticList_Delete(StaticList* list, int pos)
{
	TStaticList* slist = (TStaticList*) list;
	TStaticFreeList* TStaticFreeListLocal = (TStaticFreeList*)slist->freeList;
	
	int i = 0;
	int cunt = 0;
	int object= 0;
	
	TStaticListNode* ret = NULL;
	
	unsigned int freeLen = TStaticFreeListLocal->length;//剩余个数 
	int tic = TStaticFreeListLocal->freeHeader.data;
	unsigned int nextTic = TStaticFreeListLocal->freeHeader.next; 
	
	if((slist != NULL) && (0 <= pos) && (pos <= slist->header.data))
	{
		slist->node[cunt] = slist->header;
		
		for(i = 0; i < pos; i++)
		{
			cunt = slist->node[cunt].next;
		}
		
		object = slist->node[cunt].next;
		
		slist->node[cunt].next = slist->node[object].next;
		
		slist->node[object].next = AVIALIBLE;
		
		slist->node[0].data--;
		
		slist->header = slist->node[0];	
		
		ret = (TStaticListNode*)slist->node[object].data;
		
		if(0 == freeLen)
		{
			TStaticFreeListLocal->freeHeader.data = object;
			TStaticFreeListLocal->freeHeader.next = NULL;
		}
		else
		{
			TStaticFreeListLocal->free[object].next =  TStaticFreeListLocal->freeHeader.data;
			TStaticFreeListLocal->freeHeader = TStaticFreeListLocal->free[object];
		}
		freeLen++;
		TStaticFreeListLocal->length = freeLen;
	}
	return ret;
}
