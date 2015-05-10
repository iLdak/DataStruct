#include <stdio.h>
#include <malloc.h>
#include "LinkStack.h"
#include "SQueue.h"

typedef struct _tag_SQueue
{
	LinkStack* inStack;
	LinkStack* outStack;
}TSQueue;

SQueue* SQueue_Create()
{
	TSQueue* squeue = (TSQueue*)malloc(sizeof(TSQueue));
	
	if(squeue != NULL)
	{
		squeue->inStack = LinkStack_Creat();
		squeue->outStack = LinkStack_Creat();
		
		if((squeue->inStack == NULL) || (squeue->outStack == NULL))
		{
			LinkStack_Destroy(squeue->inStack);
			LinkStack_Destroy(squeue->outStack);
			free(squeue);
			squeue = NULL;
		}
	}
	
	return squeue;
}

void SQueue_Destroy(SQueue* queue)
{
	SQueue_Clear(queue);
	free(queue);
}

void SQueue_Clear(SQueue* queue)
{
	TSQueue* squeue = (TSQueue*)queue;	
	
	if(squeue != NULL)
	{
		LinkStack_Clear(squeue->inStack);
		LinkStack_Clear(squeue->outStack);
	}
}

void SQueue_Append(SQueue* queue, void* item)
{
	TSQueue* squeue = (TSQueue*)queue;	
	
	if(squeue != NULL)
	{
		LinkStack_Push(squeue->inStack, item);	
	}
}

void* SQueue_Departure(SQueue* queue)
{
	TSQueue* squeue = (TSQueue*)queue;
	
	void* ret = NULL;
  	
	if(squeue != NULL)
	{
		if(LinkStack_Size(squeue->outStack) == 0)
		{
			while(LinkStack_Size(squeue->inStack))
			{
				LinkStack_Push(squeue->outStack, LinkStack_Pop(squeue->inStack));	
			}
		} 
			
		if(LinkStack_Size(squeue->outStack) > 0)
		{
			ret = LinkStack_Pop(squeue->outStack);
		}	
	}
	
	return ret;
}

void* SQueue_Header(SQueue* queue)
{
	TSQueue* squeue = (TSQueue*)queue;	
	
	void* ret = NULL;
	
	if(squeue != NULL)
	{
		if( LinkStack_Size(squeue->outStack) == 0 )
		{
			while(LinkStack_Size(squeue->inStack))
			{
				LinkStack_Push(squeue->outStack, LinkStack_Pop(squeue->inStack));	
			}
		} 	
					
		if(LinkStack_Size(squeue->outStack) > 0)
		{
			ret = LinkStack_Top(squeue->outStack);
		}
	}
	
	return ret;
}

int SQueue_Length(SQueue* queue)
{
	TSQueue* squeue = (TSQueue*)queue;
	
	int ret = -1;
	
	if(squeue != NULL)
	{	
		ret = LinkStack_Size(squeue->inStack) + LinkStack_Size(squeue->outStack);
	}
	
	return ret;
}

