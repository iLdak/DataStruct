#include "BTree.h"
#include <malloc.h>

typedef struct _tar_TBTree TBTree;
struct _tar_TBTree{
	int count;
	BTreeNode* root;
};

void recursive_Display(BTreeNode* node,  BTree_Printf* pFunc, int bump, int gap, char div)
{
	int i = 0;
	if((node != NULL) && (pFunc != NULL))
	{
		for(i = 0; i < bump; i++)
		{
			printf("%c",div);
		}
		
		pFunc(node);
		
		if((node->left != NULL) || (node->right != NULL))
		{
			recursive_Display(node->left , pFunc, bump + gap, gap, div);
			recursive_Display(node->right , pFunc, bump + gap, gap, div);	
		}

	}
	else
	{
		for(i = 0; i < bump; i++)
		{
			printf("%c",div);
			
		}
		printf("\n");
	}
}

int recursive_Delete(BTreeNode* node)
{
	int ret = 0;
	
	if(node != NULL)
	{
		ret = recursive_Delete(node->left) + 1 + recursive_Delete(node->right);
	}	
	
	return ret;
}

int recursive_Height(BTreeNode* node)
{
	int ret = 0;
	
	if(node != NULL)
	{
		int lh = recursive_Height(node->left) + 1;
		int rh = recursive_Height(node->right) + 1;
		
		if(lh < rh)
		{
			ret = rh;
		}
		else
		{
			ret = lh;
		}
	}
	
	return ret;
}

int recursive_Degree(BTreeNode* node)
{
	int ret = 0;
	
	if(node != NULL)
	{
		if(node->left != NULL && node->right != NULL)
		{
			ret = 2;
		}
		else
		{
			int ld = recursive_Degree(node->left);
			int rd = recursive_Degree(node->right);
			
			if(ld < rd)
			{
				ret = rd;
			}
			else
			{
				ret = ld;
			}
		}
	}
	
	return ret;
}

BTree* BTree_Create()
{
	TBTree* Tree = (TBTree*)malloc(sizeof(TBTree));
	
	if(Tree != NULL)
	{
		Tree->count = 0;
		Tree->root = NULL;
	}
	
	return Tree;
}

void BTree_Destroy(BTree* tree)
{
	free(tree);
		
}

void BTree_Clear(BTree* tree)
{
	TBTree* mTree = (TBTree*)tree;
	
	if(mTree != NULL)
	{
		mTree->count = 0;
		mTree->root = NULL;
	}
}

int BTree_Insert(BTree* tree, BTreeNode* node, BTPos pos, int count, int flag)
{
	TBTree* mTree = (TBTree*)tree;
	
	int ret = (mTree != NULL) && (node != NULL) && (pos >= 0) && (count >= 0) && ((flag == BT_LEFT) || (flag == BT_RIGHT));
	
	int bit = 0;
	
	if(ret)
	{
		BTreeNode* parent  = NULL;
		BTreeNode* child = mTree->root;
		
  		node->left = NULL;
        node->right = NULL;
        
		while((child != NULL) && (count > 0))
		{
			bit = pos & 1;
			
			pos = pos >> 1;
		
			parent = child;
		
			if(bit == BT_LEFT)
			{
				child = child->left;
			}
			else if(bit == BT_RIGHT)
			{
				child = child->right;
			}
		
			count--;
		}
		
		if(flag == BT_LEFT)
		{
			node->left = child;
		}
		else if(flag == BT_RIGHT)
		{
			node->right = child;
		}
	
		if(parent != NULL)
		{
			if(bit == BT_LEFT)
			{
				parent->left = node;
			}
			else if(bit == BT_RIGHT)
			{
				parent->right = node;
			}
		}
		else
		{
			mTree->root = node;
		}
		
		mTree->count++;
	}
	return ret;
}

BTreeNode* BTree_Delete(BTree* tree, BTPos pos, int count)
{
	TBTree* mTree = (TBTree*)tree;
	
	BTreeNode* ret = NULL;
	
	int bit = 0;
	
	if((mTree != NULL) && (pos >= 0) && (count >= 0))
	{
		BTreeNode* parent  = NULL;
		BTreeNode* child = mTree->root;
        
		while((child != NULL) && (count > 0))
		{
			bit = pos & 1;
			
			pos = pos >> 1;
		
			parent = child;
		
			if(bit == BT_LEFT)
			{
				child = child->left;
			}
			else if(bit == BT_RIGHT)
			{
				child = child->right;
			}
		
			count--;
		}
		
		if((child != NULL) && (parent != NULL))
		{
			
			int tic = recursive_Delete(child);
			
			ret = child;
			
			if(bit == BT_LEFT)
			{
				parent->left = NULL;
			}
			else if(bit == BT_RIGHT)
			{
				parent->right = NULL;
			}
			
			mTree->count -= tic;
			
		}
		
	}	
	
	return ret;
}

BTreeNode* BTree_Get(BTree* tree, BTPos pos, int count)
{
	TBTree* mTree = (TBTree*)tree;
	
	BTreeNode* ret = NULL;
	
	int bit = 0;
	
	if((mTree != NULL) && (pos >= 0) && (count >= 0))
	{
		BTreeNode* parent  = NULL;
		BTreeNode* child = mTree->root;
        
		while((child != NULL) && (count > 0))
		{
			bit = pos & 1;
			
			pos = pos >> 1;
		
			parent = child;
		
			if(bit == BT_LEFT)
			{
				child = child->left;
			}
			else if(bit == BT_RIGHT)
			{
				child = child->right;
			}
		
			count--;
		}
		
		if((child != NULL))
		{
			ret = child;
		}	
	}	
	
	return ret;
}

BTreeNode* BTree_Root(BTree* tree)
{
	TBTree* mTree = (TBTree*)tree;
	
	BTreeNode* ret = NULL;
	
	if(mTree != NULL)
	{
		ret = mTree->root;
	}
	
	return ret;
}

int BTree_Height(BTree* tree)
{
	TBTree* mTree = (TBTree*)tree;
	
	int ret = 0;
	
	if(mTree != NULL)
	{
		ret = recursive_Height(mTree->root);
	}
	
	return ret;
}

int BTree_Count(BTree* tree)
{
	TBTree* mTree = (TBTree*)tree;
	
	int ret = -1;
	
	if(mTree != NULL)
	{
		ret = mTree->count;
	}
	
	return ret;
}

int BTree_Degree(BTree* tree)
{
	TBTree* mTree = (TBTree*)tree;
	
	int ret = 0;
	
	if(mTree != NULL)
	{
		ret = recursive_Degree(mTree->root);
	}
	
	return ret;
}

void BTree_Display(BTree* tree, BTree_Printf* pFunc, int gap, char div)
{
	TBTree* mTree = (TBTree*)tree;
	
	if((mTree != NULL) && (pFunc != NULL))
	{
		recursive_Display(mTree->root, pFunc, 0, gap, div);
	} 
}
