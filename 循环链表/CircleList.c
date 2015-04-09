#include <stdio.h>
#include <malloc.h>
#include "CircleList.h"

typedef struct _tar_circle_list //circle list struct
{
	CircleListNode head; 		//list head
	CircleListNode* slider; 	//list cursor
	int len; 					//list length
}TList;

CircleList* CircleList_Create()
{
	TList* list = (TList*)malloc(sizeof(TList));
	
	if(list != NULL)
	{
		list->head.next = NULL;
		list->slider = NULL;
		list->len =0;
	}
	return list;
};

void CircleList_Destroy(CircleList* list)
{
	free(list); 
} 

void CircleList_Clear(CircleList* list)
{
	TList* sList = (TList*)list;
	
	if(sList != NULL)
	{
		sList->head.next = NULL;
		sList->slider = NULL;
		sList->len =0;
	}
}

int CircleList_Length(CircleList* list)
{
	TList* sList = (TList*)list;
	
	int ret = -1;
	
	if(sList != NULL)
	{
		ret = sList->len;
	}
	
	return ret;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
	TList* sList = (TList*)list;
	int ret = (sList != NULL) && (pos >= 0) && (node != NULL);
	int i = 0;
	
	if(ret)
	{
		CircleListNode* current = (CircleListNode*)sList;
		CircleListNode* current_pos_is_0 = NULL;
		
		for(i =0; (i < pos) && (current->next != NULL); ++i)
		{
			current = current->next;
		} 
		
		node->next = current->next;
		current->next = node;
		
		sList->len++;
		
		if(sList->len == 1)
		{
			node->next = node;
			sList->slider = node;
		}
  		else if(pos == 0)
        {
			current_pos_is_0 = CircleList_Get(list,(sList->len - 1));
			current_pos_is_0->next = node;
		}	
	}
	return ret;
}

CircleListNode* CircleList_Get(CircleList* list, int pos)
{
	TList* sList = (TList*)list;
	CircleListNode* ret = NULL;
	int ops = (sList != NULL) && (pos >= 0) && (sList->len > 0);
	int i = 0;
	
	if(ops)
	{
		CircleListNode* current = (CircleListNode*)sList;
		
		for(i =0; i < pos; ++i)
		{
			current = current->next;
		} 
		
		ret = current->next;
	}
	
	return ret;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos)
{
	TList* sList = (TList*)list;
	CircleListNode* ret = NULL;
	int ops = (sList != NULL) && (pos >= 0) && (sList->len > 0);
	int i = 0;
	
	if(ops)
	{
		CircleListNode* current = (CircleListNode*)sList;
		CircleListNode* current_last = NULL;
		
		for(i =0; i < pos; ++i)
		{
			current = current->next;
		} 
		
		ret = current->next;
		current->next = ret->next;
		
		if(pos == 0)
		{
			current_last = CircleList_Get(list,(sList->len - 1));
			current_last->next = ret->next;
		}
		
		if(sList->slider == ret)
		{
			sList->slider = ret->next;
		}
		
		sList->len--;
	}
	
	return ret;
}

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node)
{
	TList* sList = (TList*)list;
	CircleListNode* ret = NULL;
	int ops = (sList != NULL) && (sList->len > 0);
	int i = 0;
	
	if(ops)
	{
		CircleListNode* current = (CircleListNode*)sList;
		
		for(i =0; (i < (sList->len)) && (current->next != node); ++i)
		{
			current = current->next;
		} 
		
		if(current->next == node)
		{
			ret = CircleList_Delete(list, i);		
		}
		
	}
	
	return ret;
}

CircleListNode* CircleList_Reset(CircleList* list)
{
	TList* sList = (TList*)list;
	CircleListNode* ret = NULL;
	int ops = (sList != NULL) && (sList->len > 0);
	
	if(ops)
	{
		sList->slider = sList->head.next;
		ret = sList->slider;
	}
	
	return ret;
}

CircleListNode* CircleList_Current(CircleList* list)
{
	TList* sList = (TList*)list;
	CircleListNode* ret = NULL;
	int ops = (sList != NULL) && (sList->len > 0);
	
	if(ops)
	{
		ret = sList->slider;
	}
	
	return ret;
}

CircleListNode* CircleList_Next(CircleList* list)
{
	TList* sList = (TList*)list;
	CircleListNode* ret = NULL;
	int ops = (sList != NULL) && (sList->len > 0) && (sList->slider != NULL);
	
	if(ops)
	{
		ret = sList->slider;
		sList->slider = ret->next;
	}
	
	return ret;
}
