#include <stdio.h>
#include <malloc.h>
#include "DLinkList.h"

typedef struct _tar_circle_list //circle list struct
{
	DLinkListNode head; 	//list head
	DLinkListNode* slider; 	//list cursor
	int len; 		//list length
}TDLinkList;

DLinkList* DLinkList_Create()
{
	TDLinkList* list = (TDLinkList*)malloc(sizeof(TDLinkList));
	
	if(list != NULL)
	{
		list->head.next = NULL;
		list->head.header = NULL;
		list->slider = NULL;
		list->len =0;
	}
	return list;
};

void DLinkList_Destroy(DLinkList* list)
{
	free(list); 
} 

void DLinkList_Clear(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	
	if(sList != NULL)
	{
		sList->head.next = NULL;
		sList->head.header = NULL;
		sList->slider = NULL;
		sList->len =0;
	}
}

int DLinkList_Length(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	
	int ret = -1;
	
	if(sList != NULL)
	{
		ret = sList->len;
	}
	
	return ret;
}

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)
{
	TDLinkList* sList = (TDLinkList*)list;
	int ret = (sList != NULL) && (pos >= 0) && (node != NULL);
	int i = 0;
	
	if(ret)
	{
		DLinkListNode* current = (DLinkListNode*)sList;
		DLinkListNode* current_pos_is_0 = NULL;
		DLinkListNode* current_node = NULL;
		
		for(i =0; (i < pos) && (current->next != NULL); ++i)
		{
			current = current->next;
		} 
		current_node = current->next;
		node->next = current->next;
		current->next = node;
		
		sList->len++;
		
		if(sList->len == 1)
		{
			node->header = NULL;
			sList->slider = node;	
		}
  		else if(pos == 0)
        	{
			node->header = NULL;

		}
		else
		{
			node->header = current;
		}
		
		if(current_node != NULL)
		{
			current_node->header = node;
		}		
	}
	return ret;
}

DLinkListNode* DLinkList_Get(DLinkList* list, int pos)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int ops = (sList != NULL) && (0	<= pos) && (pos < (sList->len)) && (sList->len > 0);
	int i = 0;
	
	if(ops)
	{
		DLinkListNode* current = (DLinkListNode*)sList;
		
		for(i =0; i < pos; ++i)
		{
			current = current->next;
		} 
		
		ret = current->next;
	}
	
	return ret;
}

DLinkListNode* DLinkList_Delete(DLinkList* list, int pos)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int ops = (sList != NULL) && (pos >= 0) && (sList->len > 0);
	int i = 0;
	
	if(ops)
	{
		DLinkListNode* current = (DLinkListNode*)sList;
		DLinkListNode* first = sList->head.next;
		DLinkListNode* current_node = NULL;
		
		for(i = 0; i < pos; ++i)
		{
			current = current->next;
		}

		ret = current->next;
		current->next = ret->next;
		current_node = ret->next;
		
		if(first == ret)
		{
			sList->head.next = ret->next;
			
			if(current_node != NULL)
				current_node->header = NULL;
		}
		else
		{
			if(current_node != NULL)
				current_node->header = current;
		}
		
		if(sList->slider == ret)
		{
			if(current_node != NULL)
			{
				sList->slider = ret->next;
			}
			else
			{
				sList->slider = ret->header;
			}	
		}
		
		sList->len--;
		
		if(sList->len == 0)
		{
			sList->slider = NULL;
			sList->head.next = NULL;
		}
	}
	
	return ret;
}

DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int ops = (sList != NULL) && (sList->len > 0);
	int i = 0;
	
	if(ops)
	{
		DLinkListNode* current = (DLinkListNode*)sList;
		
		for(i =0; (i < (sList->len)) && (current->next != node); ++i)
		{
			current = current->next;
		} 
		
		if(current->next == node)
		{
			ret = DLinkList_Delete(list, i);		
		}
		
	}
	
	return ret;
}

DLinkListNode* DLinkList_Reset(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int ops = (sList != NULL);
	
	if(ops)
	{
		sList->slider = sList->head.next;
		ret = sList->slider;
	}
	
	return ret;
}

DLinkListNode* DLinkList_Current(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int ops = (sList != NULL) && (sList->len > 0);
	
	if(ops)
	{
		ret = sList->slider;
	}
	
	return ret;
}

DLinkListNode* DLinkList_Next(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int ops = (sList != NULL) && (sList->len > 0) && (sList->slider != NULL);
	
	if(ops)
	{
		ret = sList->slider;
		sList->slider = ret->next;
	}
	
	return ret;
}

DLinkListNode* DLinkList_Per(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int ops = (sList != NULL) && (sList->len > 0) && (sList->slider != NULL);
	
	if(ops)
	{
		ret = sList->slider;
		sList->slider = ret->header;
	}
	
	return ret;
}
