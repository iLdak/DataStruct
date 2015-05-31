#include <stdio.h>
#include "GTree.h"
#include "LinkList.h"
#include <malloc.h>

typedef struct _tag_GTreeNode GTreeNode;
struct _tag_GTreeNode
{
	GTreeDate *date;
	GTreeNode *parents;
	LinkList *child;
};

typedef struct _tag_TLNode TLNode;
struct _tag_TLNode
{
	LinkListNode *header;
	GTreeNode *node;
};

void GTree_recursive_Display(GTreeNode *tlnode, callback* fun, char* div, int number, int gap)
{
	int i = 0;
	
	if(tlnode != NULL)
	{
		for(i = 0; i < gap ; i++)
		{
			printf("%s",div);
		}
		
		fun(tlnode->date);
		
		for(i = 0; i < LinkList_Length(tlnode->child); i++)
		{
			TLNode* tnode = (TLNode*)LinkList_Get(tlnode->child, i);
			
			GTree_recursive_Display(tnode->node, fun, div, number, gap+number);
		}
	}
}

void GTree_recursive_Delet(GTree* tree, GTreeNode *gtnode)
{
	LinkList* list = (LinkList*)tree;
	
	int ret = ((tree != NULL) && (gtnode != NULL));
	
	int i = 0;
	
	int flag = -1;
	
	if(ret)
	{
		for(i = 0; i < LinkList_Length(list); i++)
		{
			TLNode* tlnode = (TLNode*)LinkList_Get(list, i);
			
			if(tlnode->node == gtnode)
			{
				LinkList_Delete(list, i);
				free(tlnode);
				flag = i;
				break;
			}
		}
 
		if(flag >= 0)
		{
			GTreeNode* parent = gtnode->parents;
			
			if(parent != NULL)
			{
				for(i = 0; i < LinkList_Length(gtnode->parents->child); i++)
				{
					TLNode* tlnode = (TLNode*)LinkList_Get(gtnode->parents->child, i);
			
					if(tlnode->node == gtnode)
					{
						LinkList_Delete(gtnode->parents->child, i);
						free(tlnode);
						break;
					}
				}
			}

			while(LinkList_Length(gtnode->child) > 0)
			{
				TLNode* tlnode = (TLNode*)LinkList_Get(gtnode->child, 0);
				GTree_recursive_Delet(list, tlnode->node);
			}
	
			LinkList_Destroy(gtnode->child);

			free(gtnode);
	;
		}
	} 
} 

int GTree_recursive_Height(GTreeNode* gtreenode)
{
	int ret = 0;
	
	int i = 0;
	
	int layerNumber = 1;
	
	if(gtreenode != NULL)
	{
		for(i = 0; i < LinkList_Length(gtreenode->child); i++)
		{
			TLNode* tlnode = (TLNode*)LinkList_Get(gtreenode->child, i);
			layerNumber = 	GTree_recursive_Height(tlnode->node);
			
			if(ret < layerNumber)
			{
				ret = layerNumber;
			}
		}
		
		ret += 1;	
	}

	return ret;
}

int GTree_recursive_Degree(GTreeNode* gtreenode)
{
	int ret = 0;
	int i = 0;
	int degreeNumber = 0;

	if(gtreenode != NULL)
	{
		ret = LinkList_Length(gtreenode->child);
		
		for(i  = 0; i < ret; i++)
		{
			TLNode* tlnode = (TLNode*)LinkList_Get(gtreenode->child, i);
			degreeNumber = GTree_recursive_Degree(tlnode->node);
			
			if(ret < degreeNumber)
				ret = degreeNumber;
		}
		
	}
	
	return ret;
}

void GTree_recursive_Search_Parents(GTreeNode* parents, callbackTwo* fun)
{
	if(parents != NULL)
	{
		GTree_recursive_Search_Parents(parents->parents, fun);
		fun(parents->date, 1);
	}
}

void GTree_recursive_Search(GTreeNode* node, GTreeDate* data, callbackTwo* fun)
{
	int i = 0;
	
	TLNode* tlnode = NULL;
	
	if(node != NULL)
	{
		if(node->date == data)
		{
			GTree_recursive_Search_Parents(node->parents, fun);
			
			fun(node->date, 0);
		}
		else
		{
			for(i = 0; i < LinkList_Length(node->child); i++)
			{
				tlnode = (TLNode*)LinkList_Get(node->child, i);
				
				GTree_recursive_Search(tlnode->node, data, fun);
			}	
		} 
	}
}

GTree* GTree_Create()
{
	return LinkList_Create();
}

void GTree_Destroy(GTree* tree)
{
	GTree_Clear(tree);
	LinkList_Destroy(tree);
}

void GTree_Clear(GTree* tree)
{
	GTree_Delete(tree, 0);
}

int GTree_Insert(GTree* tree, GTreeDate* date, int pPos)
{
	LinkList* list = (LinkList*)tree;
	
	GTreeNode *mGnode = (GTreeNode*)malloc(sizeof(GTreeNode));
	TLNode *mnode = (TLNode*)malloc(sizeof(TLNode));
	TLNode *cnode = (TLNode*)malloc(sizeof(TLNode));
	 
 	int ret = (list != NULL) && (mGnode != NULL) && (mnode != NULL) && (cnode != NULL) && (date != NULL) && (pPos < LinkList_Length(list));
	
	if(ret)
	{
		//取出组织链表的第一个结点 
		TLNode *listNode = (TLNode*)LinkList_Get(list, LinkList_Length(list) - 1);
		
		mGnode->date = date;
		mGnode->parents = NULL;
		mGnode->child = LinkList_Create();
	
		if(listNode == NULL)//为空，说明现在要创建的这个结点为根结点 
		{
			free(cnode);
		}
		else//不是创建根结点 
		{
			TLNode *knode = (TLNode*)LinkList_Get(list, pPos);
			mGnode->parents = knode->node;
			cnode->node = mGnode;
			LinkList_Insert(mGnode->parents->child, (LinkListNode*)cnode, LinkList_Length(mGnode->parents->child));
		}
		
		mnode->node =  mGnode;
		LinkList_Insert(list, (LinkListNode*)mnode, LinkList_Length(list));
	}
	else
	{
		free(mGnode);
		free(mnode);
		free(cnode);
	}
	
	return ret;
}


GTreeDate* GTree_Delete(GTree* tree, int pos)
{
	LinkList* list = (LinkList*)tree;
	TLNode *tlnode = (TLNode*)LinkList_Get(list, pos);
	GTreeDate* ret = NULL;

	if((tlnode != NULL))
	{
		ret = tlnode->node->date;
		
		GTree_recursive_Delet(tree, tlnode->node);
	} 

	return NULL;
}

GTreeDate* GTree_Get(GTree* tree, int pos)
{
	LinkList* list = (LinkList*)tree;
	GTreeDate* ret = NULL;
	
	if((list != NULL) && ((0 <= pos) && (pos < LinkList_Length(list))))
	{
		TLNode* tlnode = (TLNode*)LinkList_Get(list, pos);
		ret = tlnode->node->date;
	}
	
	return ret;
}

GTreeDate* GTree_Root(GTree* tree)
{
	return GTree_Get(tree, 0);
}

int GTree_Height(GTree* tree)
{
	LinkList* list = (LinkList*)tree;
	
	int ret = -1;
	
	if(list != NULL)
	{
		TLNode* tlnode = (TLNode*)LinkList_Get(list, 0);
		ret = GTree_recursive_Height(tlnode->node);
	}
	
	return ret;
}

int GTree_Count(GTree* tree)
{
	LinkList* list = (LinkList*)tree;
	int ret = -1;
	
	if(list != NULL)
	{
		ret = LinkList_Length(list);
	}
	
	return ret;
}

int GTree_Degree(GTree* tree)
{
	LinkList* list = (LinkList*)tree;
	
	int ret = -1;
	
	if(list != NULL)
	{
		TLNode* tlnode = (TLNode*)LinkList_Get(list, 0);
		ret = GTree_recursive_Degree(tlnode->node);
	}
	
	return ret;
}

void GTree_Display(GTree* tree, callback* fun, char* div, int number)
{
	LinkList* mtree = (LinkList*)tree;
	TLNode *tnode = (TLNode*)LinkList_Get(mtree, 0);
	
	if(tnode != NULL && fun != NULL)
	{
		GTree_recursive_Display(tnode->node, fun, div, number, 0);
	}
	
}

int GTree_Search(GTree* tree, GTreeDate* data, callbackTwo* fun)
{
	LinkList* list = (LinkList*)tree;
	int ret = (list != NULL) && (data != NULL) && (fun != NULL); 
	int i = 0;
	int flag = 0;
	TLNode* tlnode =  NULL;
	
	if( ret )
	{
		for( i = 0; i < LinkList_Length(list); i++)
		{
			tlnode = (TLNode*)LinkList_Get(list, i);
			
			if((tlnode != NULL) && (tlnode->node->date == data))
			{
				flag = 1;
				ret = i;
				break;	
			}
		}
		
		if(flag != 0)
		{
			tlnode = (TLNode*)LinkList_Get(list, 0);
			
			GTree_recursive_Search(tlnode->node, data, fun);
		}
	}
	
	return ret;
}
