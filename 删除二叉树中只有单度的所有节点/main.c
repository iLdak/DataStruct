#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"

struct Node{
	BTreeNode node;
	char c;
};

void printfDate(BTreeNode* node)
{
	if(node != NULL)
	{
		printf("%c\n", ((struct Node*)node)->c);
	}

}

void SingleDegreeDelet(BTree* tree, BTreeNode* node, BTreeNode* pnode)
{
	int i = 1;
	if(node != NULL)
	{
		while( i && (node != NULL))
		{
			i = 0;
			if(node == pnode)
			{
				if(node->left == NULL && node->right != NULL) //右单度 
				{
				    ((struct Node *)pnode)->c = ((struct Node *)(pnode->right))->c;
				    //((struct Node *)pnode)->node = *(node->left);
					*(pnode) = *(node->right);
					//*(node) = *(node->left);
					//BTree_Delete(tree, 1, 0);
					i = 1;
				}
				else if(node->left != NULL && node->right == NULL)//左单度 
				{
				    ((struct Node *)pnode)->c = ((struct Node *)(pnode->left))->c;
				    //((struct Node *)pnode)->node = *(node->left);
					*(pnode) = *(node->left);
					//*(node) = *(node->left);
					//BTree_Delete(tree, 1, 0);
					i = 1;
				}
				
			}
			else
			{
				if(node->left == NULL && node->right != NULL) //右单度 
				{
					if(pnode->right == node)
					{
						pnode->right = node->right;
					}
					else
					{
						pnode->left = node->right;
					}
					node = node->right;
				 	i = 1;
				}
				else if(node->left != NULL && node->right == NULL)//左单度 
				{
					if(pnode->right == node)
					{
						pnode->right = node->left;
					}
					else
					{
						pnode->left = node->left;
					}
					node = node->left;
					i = 1;
				}
			}
		}
		
		if(node != NULL)
		{
			SingleDegreeDelet(tree, node->left, pnode);
			SingleDegreeDelet(tree, node->right, pnode); 		
		}
	}
}

int main(int argc, char *argv[])
{
  BTreeNode* current = NULL;
  BTree* tree = BTree_Create();
  
  struct Node v1 = {{NULL, NULL}, 'A'};;
  struct Node v2 = {{NULL, NULL}, 'B'};;
  struct Node v3 = {{NULL, NULL}, 'C'};;
  struct Node v4 = {{NULL, NULL}, 'D'};;
  struct Node v5 = {{NULL, NULL}, 'E'};;
  struct Node v6 = {{NULL, NULL}, 'F'};;
  struct Node v7 = {{NULL, NULL}, 'G'};;
  struct Node* mnode = NULL;

  BTree_Insert(tree, (BTreeNode*)&v1, 0, 0, 0);
  BTree_Insert(tree, (BTreeNode*)&v2, 0x01, 1, BT_RIGHT);
  BTree_Insert(tree, (BTreeNode*)&v3, 0x03, 2, BT_RIGHT);
  BTree_Insert(tree, (BTreeNode*)&v4, 0x07, 3, BT_RIGHT);
  //BTree_Insert(tree, (BTreeNode*)&v5, 0x00, 3, BT_LEFT);
  //BTree_Insert(tree, (BTreeNode*)&v6, 0x00, 4, BT_LEFT);
  //BTree_Insert(tree, (BTreeNode*)&v7, 0x08, 4, BT_RIGHT);
  
  printf("Full BTree Height:%d\n",BTree_Height(tree));
  
  printf("Full BTree node count:%d\n",BTree_Count(tree));
  
  printf("BTree degree:%d\n",BTree_Degree(tree));

  printf("Full BTree:\n");
  BTree_Display(tree, printfDate, 2, '-');
  
  current = BTree_Root(tree);
  SingleDegreeDelet(tree, current, current);
  
  printf("Full BTree:\n");
  BTree_Display(tree, printfDate, 2, '-');
  
  BTree_Destroy(tree);
  
  printf("Press enter to continue ...");
  getchar();	
  return 0;

}
