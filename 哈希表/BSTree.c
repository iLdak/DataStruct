#include "BSTree.h"
#include <malloc.h>

typedef struct _tar_TBSTree TBSTree;
struct _tar_TBSTree{
	int count;
	BSTreeNode* root;
};

static void recursive_Display(BSTreeNode* node,  BSTree_Printf* pFunc, int bump, int gap, char div)
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

static int recursive_Delete(BSTreeNode* node)
{
	int ret = 0;
	
	if(node != NULL)
	{
		ret = recursive_Delete(node->left) + 1 + recursive_Delete(node->right);
	}	
	
	return ret;
}

static int recursive_Height(BSTreeNode* node)
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

static int recursive_Degree(BSTreeNode* node)
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

static int BSTree_Insert_Recursive(BSTreeNode* root, BSTreeNode* node, BSTree_Comparison* Comparison)
{
	int ret = 1;

	if( Comparison(root->key, node->key) == 0 )
	{
		ret = -1;
	}
	else if( Comparison(root->key, node->key) > 0 )
	{
		if(root->left == NULL)
		{
			root->left = node;
		}
		else
		{
			BSTree_Insert_Recursive(root->left, node, Comparison);
		}
	}
	else
	{
		if(root->right == NULL)
		{
			root->right = node;
		}
		else
		{
			BSTree_Insert_Recursive(root->right, node, Comparison);
		}
	}
		
	return ret;
}	

static BSTreeNode* BSTree_Get_Recursive(BSTreeNode* node, BSKey* key, BSTree_Comparison* Comparison)
{
	BSTreeNode* ret = NULL;
	
	if(Comparison(node->key, key) == 0)
	{
		ret = node;
	}
	else if( Comparison(node->key, key) > 0 )
	{
		if(node->left != NULL)
		{
			ret = BSTree_Get_Recursive(node->left, key, Comparison);
		}	
	}
	else if( Comparison(node->key, key) < 0 )
	{
		if(node->right != NULL)
		{
			ret = BSTree_Get_Recursive(node->right, key, Comparison);
		}	
	}
	
	return ret;
}

static BSTreeNode* BSTree_Delete_Recursive(BSTreeNode** pNode, BSKey* key, BSTree_Comparison* Comparison)
{
	BSTreeNode* ret = NULL;
	
	if( Comparison((*pNode)->key,key) == 0 )
	{
		ret = *pNode;
		
		if((*pNode)->left != NULL && (*pNode)->right == NULL)
		{
			*pNode = (*pNode)->left;
		}
		else if((*pNode)->right != NULL && (*pNode)->left == NULL)
		{
			*pNode = ((*pNode)->right);
		}
		else 
		{
			BSTreeNode* P = (*pNode)->left;
			BSTreeNode* G = (*pNode)->left;
			
			if(P->right == NULL)
			{
				pNode = &P;
			}
			else
			{
				P = P->right;
				
				while(P->right != NULL)
				{
					G = P;
					
					P = P->right;
				}
				
				G->right = P->left;
				
				P->left = (*pNode)->left;
				P->right = (*pNode)->right;
				
				*pNode = P;
			}
		}
	}
	else if( Comparison((*pNode)->key, key) > 0 )
	{
		if( (*pNode)->left != NULL )
		{
			
			ret = BSTree_Delete_Recursive( &((*pNode)->left), key, Comparison );
		}	
	}
	else if( Comparison((*pNode)->key, key) < 0 )
	{
		if( (*pNode)->right != NULL )
		{
			
			ret = BSTree_Delete_Recursive( &((*pNode)->right), key, Comparison );
		}	
	}
	
	return ret;
}

BSTree* BSTree_Create()
{
	TBSTree* Tree = (TBSTree*)malloc(sizeof(TBSTree));
	
	if(Tree != NULL)
	{
		Tree->count = 0;
		Tree->root = NULL;
	}
	
	return Tree;
}

void BSTree_Destroy(BSTree* tree)
{
	free(tree);
		
}

void BSTree_Clear(BSTree* tree)
{
	TBSTree* mTree = (TBSTree*)tree;
	
	if(mTree != NULL)
	{
		mTree->count = 0;
		mTree->root = NULL;
	}
}

int BSTree_Insert(BSTree* tree, BSTreeNode* node, BSTree_Comparison* Comparison)
{
	TBSTree* mTree = (TBSTree*)tree;
	
	int ret = (mTree != NULL) && (node != NULL) && (Comparison != NULL);
		
	if(ret)
	{
		node->left = NULL;
		node->right = NULL;
		
		if(mTree->root == NULL)
		{
			mTree->root	= node;
			ret = 1;
		}
		else if( Comparison(mTree->root->key, node->key) > 0)
		{
			if(mTree->root->left != NULL)
			{
				ret = BSTree_Insert_Recursive(mTree->root->left, node, Comparison);
			}
			else
			{
				mTree->root->left = node;
				ret = 1;
			}
		}
		else if( Comparison(mTree->root->key, node->key) < 0)
		{
			if(mTree->root->right != NULL)
			{
				ret = BSTree_Insert_Recursive(mTree->root->right, node, Comparison);
			}
			else
			{
				mTree->root->right = node;
				ret = 1;
			}
		}
		else
		{
			ret = -1;
		}
		
		if(ret >= 0)
			mTree->count++;
	}
	
	return ret;
}

BSTreeNode* BSTree_Delete(BSTree* tree, BSKey* key, BSTree_Comparison* Comparison)
{
	TBSTree* mTree = (TBSTree*)tree;
	
	BSTreeNode* ret = NULL;
	
	if((mTree != NULL) && (key != NULL) && (Comparison != NULL))
	{
		ret = BSTree_Delete_Recursive(&(mTree->root), key, Comparison);
		
		if(ret != NULL)
			mTree->count--;
	}	
	
	return ret;
}

BSTreeNode* BSTree_Get(BSTree* tree, BSKey* key, BSTree_Comparison* Comparison)
{
	TBSTree* mTree = (TBSTree*)tree;
	
	BSTreeNode* ret = NULL;
	
	int bit = 0;
	
	if((mTree != NULL) && (key != NULL) && (Comparison != NULL))
	{
		ret = BSTree_Get_Recursive(mTree->root, key, Comparison);
	}	
	
	return ret;
}

BSTreeNode* BSTree_Root(BSTree* tree)
{
	TBSTree* mTree = (TBSTree*)tree;
	
	BSTreeNode* ret = NULL;
	
	if(mTree != NULL)
	{
		ret = mTree->root;
	}
	
	return ret;
}

int BSTree_Height(BSTree* tree)
{
	TBSTree* mTree = (TBSTree*)tree;
	
	int ret = 0;
	
	if(mTree != NULL)
	{
		ret = recursive_Height(mTree->root);
	}
	
	return ret;
}

int BSTree_Count(BSTree* tree)
{
	TBSTree* mTree = (TBSTree*)tree;
	
	int ret = -1;
	
	if(mTree != NULL)
	{
		ret = mTree->count;
	}
	
	return ret;
}

int BSTree_Degree(BSTree* tree)
{
	TBSTree* mTree = (TBSTree*)tree;
	
	int ret = 0;
	
	if(mTree != NULL)
	{
		ret = recursive_Degree(mTree->root);
	}
	
	return ret;
}

void BSTree_Display(BSTree* tree, BSTree_Printf* pFunc, int gap, char div)
{
	TBSTree* mTree = (TBSTree*)tree;
	
	if((mTree != NULL) && (pFunc != NULL))
	{
		recursive_Display(mTree->root, pFunc, 0, gap, div);
	} 
}
