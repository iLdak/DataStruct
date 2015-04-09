#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "TseqList.h"

typedef unsigned int TseqListNode;

typedef struct
{
    int catcity;//要创建的列表长度 
    int length;//当前列表的长度位置 
    TseqListNode* node; //线性列表的起始地址，表中的数据元素类型为TseqListNode
}TseqList;

//创建线性列表 
seqList* SeqList_Create(int capacity)
{
	TseqList* ret = NULL;
	if(capacity >= 0)
		ret = (TseqList*)malloc(sizeof(TseqList) + sizeof(TseqListNode) * capacity);
	
	if(ret != NULL)
	{
		ret->catcity = capacity;
		ret->length = 0;
		ret->node = (TseqListNode*)(ret + 1);//指针的使用技巧 
	}
	
	return ret;
}

//销毁线性列表 
void SeqList_Destroy(seqList* list)
{
	TseqList* sList =(TseqList*)list;
	
	if(sList != NULL)
		free(list);
}

//清空线性列表 
void SeqList_Clear(seqList* list)
{
	TseqList* sList =(TseqList*)list;
	
	if(sList != NULL)
		sList->length = 0;
}

//获取当前列表已经使用的长度 
int SeqList_Length(seqList* list)
{
	TseqList* sList =(TseqList*)list;
	int ret = -1;
	
	if(sList != NULL)
		ret = sList->length; 
	
	return ret;
}

//获取列表的总长度 
int SeqList_Capacity(seqList* list)
{
	TseqList* sList =(TseqList*)list;
	int ret = -1;
	if(sList != NULL)
		ret = sList->catcity; 
	
	return ret;
} 
	 
//向线性表的指定位置插入数据元素 
int SeqList_Insert(seqList* list, seqListNode* node, int pos)
{
	TseqList* sList =(TseqList*)list;
	
	int i = 0,ret = -1;
	
	int ops = (sList != NULL) && (sList->length < sList->catcity);

	ops = ops && (pos >= 0);

	if(ops)
	{
		if(pos >= sList->length)
			pos = sList->length;

		for(i = sList->length; i > pos; i--)
		{
			sList->node[i] = sList->node[i - 1];
		}

		TseqListNode* sNode = (TseqListNode*)node;
		sList->node[pos] = (TseqListNode)node;
		

		sList->length++;
		ret = 0;
	}
	
	return ret;
} 

//获取线性表中的指定位置数据元素 
seqListNode* SeqList_Get(seqList* list, int pos)
{
	TseqList* sList =(TseqList*)list;
	
	TseqListNode* ret = NULL;
	
	if((sList != NULL) && (0 <= pos) && (pos < sList->length))
		ret = sList->node[pos];
		
	return ret;
	
}

//删除线性表中指定位置的数据元素 
seqListNode* SeqList_Delete(seqList* list, int pos)
{
	TseqList* sList =(TseqList*)list;
	TseqListNode* ret = SeqList_Get(list,pos);
	int i = 0;
	
	if(ret != NULL)
	{
		for(i = pos + 1; i < sList->length; i++)
		{
			sList->node[i - 1] = sList->node[i];
		}
		sList->length--;
	}
	
	return ret;
}
