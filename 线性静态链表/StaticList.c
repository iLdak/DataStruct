#include <stdio.h>
#include <malloc.h>
#include "StaticList.h"

#define AVIALIBLE -1

typedef struct _tag_StaticListNode
{
	unsigned int data;
	int next;
}TStaticListNode;

typedef struct _tag_StaticList
{
	unsigned int capacity;
	TStaticListNode header;
	TStaticListNode node[];
}TStaticList;

StaticList* StaticList_Create(int capacity1)
{
	TStaticList* ret = NULL;
	int i = 0;
	
	if(capacity1 >= 0)
		ret = (TStaticList*)malloc(sizeof(TStaticList) + (sizeof(TStaticListNode) * (capacity1 + 1)));
		
	if(ret != NULL)
	{
		ret->capacity = capacity1;
		ret->header.data = 0;
		ret->header.next = 0;
		
		for(i = 1; i <= ret->capacity; i++)
		{
			ret->node[i].next = AVIALIBLE;
		}
	}
		
	return ret;
}

void StaticList_Destroy(StaticList* list)
{
	free(list);
}

void StaticList_Clear(StaticList* list)
{
	TStaticList* slist = (TStaticList*) list;
	int i = 0;
	if(slist != NULL)
	{
		slist->header.data = 0;
		slist->header.next = 0;
		
		for(i = 1; i <= slist->capacity; i++)
		{
			slist->node[i].next = AVIALIBLE;
		}
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
	
	int i = 0;
	int index = 0;
	int cunt = 0;
	
	int ret = (slist != NULL);
	ret = ret && (0 <= pos) && (pos <= slist->capacity);
	ret = ret && (slist->capacity > slist->header.data);
	
	if(ret)
	{
		for(i = 1; i <= slist->capacity; i++)
		{
			if(AVIALIBLE == slist->node[i].next)
			{
				index = i;
				break;
			}
		}
		
		slist->node[index].data = (unsigned int)node;
		slist->node[cunt] = slist->header;
		
		for(i = 0; (i < pos) && (slist->node[cunt].next != 0); i++)
		{
			cunt = slist->node[cunt].next;
		}
		
		slist->node[index].next = slist->node[cunt].next;
		
		slist->node[cunt].next = index;
		
		slist->node[0].data++;
		
		slist->header = slist->node[0];	
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
	
	int i = 0;
	int cunt = 0;
	int object= 0;
	
	TStaticListNode* ret = NULL;
	
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
	}
	return ret;
}
