#include <stdio.h>
#include "SeqStack.h"

SeqStack* SeqStack_Creat(int capacity)//O(1)
{
	return (SeqStack*)SeqList_Create(capacity);
}

void SeqStack_Destroy(SeqStack* stack)//O(1)
{
	SeqList_Destroy(stack);
}

void SeqStack_Clear(SeqStack* stack)//O(1)
{
	SeqList_Clear(stack);
}

int SeqStack_Push(SeqStack* stack, void* node)//O(n)
{
	return SeqList_Insert(stack, node, 0);
}

void* SeqStack_Pop(SeqStack* stack)//O(n)
{
	return (void*)SeqList_Delete(stack, 0);
}

void* SeqStack_Top(SeqStack* stack)//O(1)
{
	return (void*)SeqList_Get(stack, 0);
}

int SeqStack_Size(SeqStack* stack)//O(1)
{
	return SeqList_Length(stack);
}

int SeqStack_Capacity(SeqStack* stack)//O(1)
{
	return SeqList_Capacity(stack);
}
