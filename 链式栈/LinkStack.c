#include <stdio.h>
#include <malloc.h>
#include "LinkStack.h"
#include "LinkList.h"

typedef struct _tag_LinkStack
{
	LinkListNode header;
	void* node;
}TLinkStack;

LinkStack* LinkStack_Creat()
{
	return (LinkStack*)LinkList_Create();
}

void LinkStack_Destroy(LinkStack* stack)
{
	while(LinkList_Length(stack) > 0)
	{
		LinkStack_Pop(stack);
	}
	
	LinkList_Destroy(stack);
}

void LinkStack_Clear(LinkStack* stack)
{
	while(LinkList_Length(stack) > 0)
	{
		LinkStack_Pop(stack);
	}
	
	LinkList_Clear(stack);
}

int LinkStack_Push(LinkStack* stack, void* node)
{
	TLinkStack* tagNode =  (TLinkStack*)malloc(sizeof(TLinkStack));
	
	int ret = -1;
	
	if(tagNode != NULL)
	{
		tagNode->node = node;
		
		ret = LinkList_Insert(stack, (LinkListNode*)tagNode, 0);
	}
	else
	{
		free(tagNode);
	}
	
	return ret;
}

void* LinkStack_Pop(LinkStack* stack)
{
	TLinkStack* tagNode = (TLinkStack*)LinkList_Delete(stack, 0);
	void* ret = NULL;
	
	if(tagNode != NULL)
	{
		ret = tagNode->node;
		
		free(tagNode);
	}
	
	return ret;
}

void* LinkStack_Top(LinkStack* stack)
{
	TLinkStack* tagNode = (TLinkStack*)LinkList_Get(stack, 0);
	void* ret = NULL;
	
	if(tagNode != NULL)
	{
		ret = tagNode->node;
	}
	
	return ret;
}

int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}
