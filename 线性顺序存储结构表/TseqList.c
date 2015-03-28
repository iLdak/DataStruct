#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "TseqList.h"

typedef unsigned int TseqListNode;

typedef struct
{
    int catcity;//Ҫ�������б��� 
    int length;//��ǰ�б�ĳ���λ�� 
    TseqListNode* node; //�����б����ʼ��ַ�����е�����Ԫ������ΪTseqListNode
}TseqList;

//���������б� 
seqList* SeqList_Create(int capacity)
{
	TseqList* ret = NULL;
	if(capacity >= 0)
		ret = (TseqList*)malloc(sizeof(TseqList) + sizeof(TseqListNode) * capacity);
	
	if(ret != NULL)
	{
		ret->catcity = capacity;
		ret->length = 0;
		ret->node = (TseqListNode*)(ret + 1);//ָ���ʹ�ü��� 
	}
	
	return ret;
}

//���������б� 
void SeqList_Destroy(seqList* list)
{
	TseqList* sList =(TseqList*)list;
	
	if(sList != NULL)
		free(list);
}

//��������б� 
void SeqList_Clear(seqList* list)
{
	TseqList* sList =(TseqList*)list;
	
	if(sList != NULL)
		sList->length = 0;
}

//��ȡ��ǰ�б��Ѿ�ʹ�õĳ��� 
int SeqList_Length(seqList* list)
{
	TseqList* sList =(TseqList*)list;
	int ret = -1;
	
	if(sList != NULL)
		ret = sList->length; 
	
	return ret;
}

//��ȡ�б���ܳ��� 
int SeqList_Capacity(seqList* list)
{
	TseqList* sList =(TseqList*)list;
	int ret = -1;
	if(sList != NULL)
		ret = sList->catcity; 
	
	return ret;
} 
	 
//�����Ա��ָ��λ�ò�������Ԫ�� 
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

//��ȡ���Ա��е�ָ��λ������Ԫ�� 
seqListNode* SeqList_Get(seqList* list, int pos)
{
	TseqList* sList =(TseqList*)list;
	
	TseqListNode* ret = NULL;
	
	if((sList != NULL) && (0 <= pos) && (pos < sList->length))
		ret = sList->node[pos];
		
	return ret;
	
}

//ɾ�����Ա���ָ��λ�õ�����Ԫ�� 
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
