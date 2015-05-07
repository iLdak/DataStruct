#include <stdio.h>
#include <malloc.h>
#include "LinkQueue.h"
#include "LinkList.h"

typedef struct _tag_LinkQueueNode
{
	LinkListNode header;
	void* item;
}LinkQueueNode;

LinkQueue* LinkQueue_Create()
{
	return LinkList_Create();
}

void LinkQueue_Destroy(LinkQueue* queue)
{
	LinkQueue_Clear(queue);
	LinkList_Destroy(queue);
}

void LinkQueue_Clear(LinkQueue* queue)
{
	while( LinkList_Length(queue))
	{
		LinkQueue_Departure(queue); 
	} 
}

void LinkQueue_Append(LinkQueue* queue, void* item)
{
	LinkQueueNode* queueNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	
 	int ret = (item != NULL) && (queueNode != NULL);
 	
 	if(ret)
 	{
		queueNode->item = item;
		
		LinkList_Insert(queue, (void*)queueNode, LinkList_Length(queue));
	} 
	else
	{
		if(queueNode != NULL)
		{
			free(queueNode); 
		} 
	}
}

void* LinkQueue_Departure(LinkQueue* queue)
{
	LinkQueueNode* queueNode = (LinkQueueNode*)LinkList_Delete(queue, 0);
	
	void* ret = NULL;
	
	if(queueNode != NULL)
	{
		ret = queueNode->item;
		
		free(queueNode);
	}
	
	return ret;
}

void* LinkQueue_Header(LinkQueue* queue)
{
	LinkQueueNode* queueNode = (LinkQueueNode*)LinkList_Get(queue, 0);
	
	void* ret = NULL;
	
	if(queueNode != NULL)
	{
		ret = queueNode->item;
	}
	
	return ret;
} 

int LinkQueue_Length(LinkQueue* queue)
{
	return LinkList_Length(queue);
} 
