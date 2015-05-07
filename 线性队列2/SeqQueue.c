#include <stdio.h>
#include <malloc.h>
#include "SeqQueue.h"

typedef unsigned int SeqQueueNode;

typedef struct _tag_TSeqQueue
{
	unsigned int length;
	unsigned int capacity;
	unsigned int front;
	unsigned int rear;
	SeqQueueNode* node;
}TSeqQueue;

SeqQueue* SeqQueue_Create(int capacity)
{
	TSeqQueue* queue = NULL;
	
	if( capacity >= 0 )
	{
		queue = (TSeqQueue*)malloc(sizeof(TSeqQueue) + sizeof(SeqQueueNode) * capacity);
	}
	
	if( queue != NULL )
	{
		queue->length = 0;
		queue->capacity = capacity;
		queue->front = 0;
		queue->rear = 0;
		queue->node = (SeqQueueNode*)(queue + 1);
	}	
	
	return queue;
}

void SeqQueue_Destroy(SeqQueue* queue)
{
	free(queue);
}

void SeqQueue_Clear(SeqQueue* queue)
{
	if( queue != NULL )
	{
		TSeqQueue* Tqueue = (TSeqQueue*)queue;
		
		Tqueue->length = 0;
		Tqueue->front = 0;
		Tqueue->rear = 0;
	}
}

void SeqQueue_Append(SeqQueue* queue, void* item)
{
	TSeqQueue* Tqueue = (TSeqQueue*)queue;
	
	int ret = (Tqueue != NULL) && (item != NULL);
	
	ret = ret && (Tqueue->length < Tqueue->capacity);
	
	if(ret)
	{
		Tqueue->node[Tqueue->rear] = (SeqQueueNode)item;
		
		Tqueue->rear = (Tqueue->rear + 1) % Tqueue->capacity;
		
		Tqueue->length++;
	}
}

void* SeqQueue_Departure(SeqQueue* queue)
{
	TSeqQueue* Tqueue = (TSeqQueue*)queue;
	
	void* ret = NULL;
	
	if((Tqueue != NULL) && Tqueue->length > 0)
	{
		ret = (void*)Tqueue->node[Tqueue->front];
		
		Tqueue->front = (Tqueue->front + 1) % Tqueue->capacity;
		
		Tqueue->length--;
	}	
	
	return ret;
}

void* SeqQueue_Header(SeqQueue* queue)
{
	TSeqQueue* Tqueue = (TSeqQueue*)queue;
	
	void* ret = NULL;
	
	if((Tqueue != NULL) && Tqueue->length > 0)
	{
		ret = (void*)Tqueue->node[Tqueue->front];
	}	
	
	return ret;
}

int SeqQueue_Length(SeqQueue* queue)
{
	TSeqQueue* Tqueue = (TSeqQueue*)queue;
	
	int ret = 0;
	
	if(Tqueue != NULL)
	{
		ret = Tqueue->length;
	}
	
	return ret;
}

int SeqQueue_Capacity(SeqQueue* queue)
{
	TSeqQueue* Tqueue = (TSeqQueue*)queue;
	
	int ret = 0;
	
	if(Tqueue != NULL)
	{
		ret = Tqueue->capacity;
	}
	
	return ret;
}

