#include <stdio.h>
#include <malloc.h>
#include "LinkQueue.h"

typedef struct _tag_LinkQueueNode TLinkQueueNode;

typedef struct _tag_LinkQueueNode
{
	unsigned int* next;
	void* item;
};

typedef struct _tag_LinkQueue
{
	TLinkQueueNode* front;
	TLinkQueueNode* rear;
	unsigned int length;
}TLinkQueue;

LinkQueue* LinkQueue_Create()//O{1}
{
	TLinkQueue* queue = (TLinkQueue*)malloc(sizeof(TLinkQueue));
	
	if( queue != NULL )
	{
		queue->front = NULL;
		queue->rear = NULL;
		queue->length = 0;
	}
	
	return queue;
}

void LinkQueue_Destroy(LinkQueue* queue)//O{n}
{
	LinkQueue_Clear(queue);
	free(queue);
}

void LinkQueue_Clear(LinkQueue* queue)//O{n}
{
	TLinkQueue* Tqueue = (TLinkQueue*)queue;
	
	while( Tqueue->length )
	{
		LinkQueue_Departure(queue); 
	} 
}

void LinkQueue_Append(LinkQueue* queue, void* item)//O{1}
{
	TLinkQueue* Tqueue = (TLinkQueue*)queue;
	
	TLinkQueueNode* queueNode = (TLinkQueueNode*)malloc(sizeof(TLinkQueueNode));
	
 	int ret = (item != NULL) && (queueNode != NULL) && (Tqueue != NULL);
 	
 	if(ret)
 	{
		queueNode->item = item;
		
		if( Tqueue->length > 0 )
		{
			Tqueue->rear->next = (unsigned int*)queueNode;
            Tqueue->rear = (TLinkQueueNode*)queueNode;
            queueNode->next = NULL;
		}
		else
		{
			Tqueue->rear = (TLinkQueueNode*)queueNode;
            Tqueue->front = (TLinkQueueNode*)queueNode;
            queueNode->next = NULL;
		}
		
		Tqueue->length++;
	} 
	else
	{
		if( queueNode != NULL )
		{
			free(queueNode); 
		} 
	}
}

void* LinkQueue_Departure(LinkQueue* queue)//O{1}
{
	TLinkQueue* Tqueue = (TLinkQueue*)queue;
	
	TLinkQueueNode* queueNode = NULL;
	
	void* ret = NULL;
	
	if( (Tqueue != NULL) && (Tqueue->length > 0) )
	{
		queueNode = (TLinkQueueNode*)(Tqueue->front);
		
		ret = queueNode->item;
		
		Tqueue->length--;
		
		if(Tqueue->length == 0)
		{
			Tqueue->front = NULL;
			Tqueue->rear = NULL;
		}
		else
		{
			Tqueue->front = (TLinkQueueNode*)queueNode->next;
		}
		
		free(queueNode);
	}
	
	return ret;
}

void* LinkQueue_Header(LinkQueue* queue)//O{1}
{
	TLinkQueue* Tqueue = (TLinkQueue*)queue;
	
	TLinkQueueNode* queueNode = NULL;
	
	void* ret = NULL;
	
	if( (Tqueue != NULL) && (Tqueue->length > 0) )
	{
		queueNode = (TLinkQueueNode*)Tqueue->front;
		
		ret = queueNode->item;
	}
	
	return ret;
} 

int LinkQueue_Length(LinkQueue* queue)//O{1}
{
	TLinkQueue* Tqueue = (TLinkQueue*)queue;
	
	return Tqueue->length;
} 
