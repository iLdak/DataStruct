#include <stdio.h>
#include <malloc.h>
#include "LinkList.h"

typedef struct 
{
	LinkListNode header;
	int length;
}TLinkList;


LinkList* LinkList_Create()
{
	TLinkList* ret = (TLinkList*)malloc(sizeof(TLinkList));
	
	if(ret != NULL)
	{
		ret->header.next = NULL;
		ret->length = 0;
	}
	
	return ret;
}

void LinkList_Destroy(LinkList* list)
{
	if(list != NULL)
		free(list);
}

void LinkList_Clear(LinkList* list)
{
	TLinkList* slist = (TLinkList*) list;
	
	if(slist != NULL)
	{
		slist->header.next = NULL;
		slist->length = 0;
	}
}

int LinkList_Length(LinkList* list)
{
	TLinkList* slist = (TLinkList*) list;
	int ret = 0;
	
	if(slist != NULL)
	{
		ret = slist->length;
	}
	
	return ret;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	TLinkList* slist = (TLinkList*) list;
	int ret = ((slist != NULL) && (node != NULL) && (pos >= 0));
	int i = 0;
	if(ret)
	{
		LinkListNode* count = (LinkListNode*) slist;
		
		for(i = 0;i < pos;i++)
		{
			count = count->next;
		}
		node->next = count->next;
		count->next = node;
		
		slist->length++;
	}
	
	return ret;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	TLinkList* slist = (TLinkList*) list;
	LinkListNode* ret = NULL;
	int i = 0;
	if ((slist != NULL) &&  (0 <= pos) && (pos < (slist->length)))
	{
		LinkListNode* count = (LinkListNode*) slist;
		for(i = 0;i < pos;i++)
		{
			count = count->next;
		}
		
		ret = count->next;
	}
	return ret;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	TLinkList* slist = (TLinkList*) list;
	LinkListNode* ret = NULL;
	int i = 0;
	if ((slist != NULL) &&  (0 <= pos) && (pos < slist->length))
	{
		LinkListNode* count = (LinkListNode*) slist;
		for(i = 0;i < pos;i++)
		{
			count = count->next;
		}
		ret = count->next;
		count->next = ret->next;
		
		slist->length--;
	}
	
	return ret;
}
