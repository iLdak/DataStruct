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

int compare_bin_tree(BTreeNode* bt1, BTreeNode* bt2)
{
	int ret = 0;
	int retLeft = 0;
	int retRight = 0;
	
	if( (bt1 != NULL) && (bt2 != NULL) )
	{
		if( ((struct Node *)bt1)->c == ((struct Node *)bt2)->c )
		{
			ret = 1;
		}
		else
		{
			ret = 0;
		}
		
		if(ret == 1)
		{
			if(bt1->left != NULL || bt2->left != NULL)
			{
				ret = compare_bin_tree(bt1->left, bt2->left);
			} 
			
			if((ret == 1) && (bt1->right != NULL || bt2->right != NULL))
			{
				ret = compare_bin_tree(bt1->right, bt2->right);
			}	
		} 
	}
	
	return ret;
}



int main(int argc, char *argv[])
{
  BTree* tree1 = BTree_Create();
  BTree* tree2 = BTree_Create();
  
  struct Node v0_1 = {{NULL, NULL}, 'A'};
  struct Node v0_2 = {{NULL, NULL}, 'B'};
  struct Node v0_3 = {{NULL, NULL}, 'C'};
  struct Node v0_4 = {{NULL, NULL}, 'D'};
  struct Node v0_5 = {{NULL, NULL}, 'E'};
  struct Node v0_6 = {{NULL, NULL}, 'F'};
  
  struct Node v1_1 = {{NULL, NULL}, 'A'};
  struct Node v1_2 = {{NULL, NULL}, 'B'};
  struct Node v1_3 = {{NULL, NULL}, 'C'};
  struct Node v1_4 = {{NULL, NULL}, 'D'};
  struct Node v1_5 = {{NULL, NULL}, 'E'};
  struct Node v1_6 = {{NULL, NULL}, 'F'};
  
  struct Node* mnode = NULL;

  BTree_Insert(tree1, (BTreeNode*)&v0_1, 0, 0, 0);
  BTree_Insert(tree1, (BTreeNode*)&v0_2, 0x00, 1, BT_LEFT);
  BTree_Insert(tree1, (BTreeNode*)&v0_3, 0x01, 1, BT_RIGHT);
  //BTree_Insert(tree1, (BTreeNode*)&v0_4, 0x00, 2, BT_LEFT);
  //BTree_Insert(tree1, (BTreeNode*)&v0_5, 0x00, 3, BT_LEFT);
  //BTree_Insert(tree1, (BTreeNode*)&v0_6, 0x00, 4, BT_LEFT);
  

  printf("Full BTree1:\n");
  BTree_Display(tree1, printfDate, 2, '-');
  
  BTree_Insert(tree2, (BTreeNode*)&v1_1, 0, 0, 0);
  BTree_Insert(tree2, (BTreeNode*)&v1_2, 0x00, 1, BT_LEFT);
  BTree_Insert(tree2, (BTreeNode*)&v1_3, 0x01, 1, BT_RIGHT);
  BTree_Insert(tree2, (BTreeNode*)&v1_4, 0x00, 2, BT_LEFT);
  //BTree_Insert(tree2, (BTreeNode*)&v1_5, 0x00, 3, BT_LEFT);
  //BTree_Insert(tree2, (BTreeNode*)&v1_6, 0x00, 4, BT_LEFT);

  printf("Full BTree2:\n");
  BTree_Display(tree2, printfDate, 2, '-');
  
  printf("compare bintree:%d\n",compare_bin_tree(BTree_Root(tree1), BTree_Root(tree2)));
  
  BTree_Destroy(tree2);
  BTree_Destroy(tree1);
  
  printf("Press enter to continue ...");
  getchar();	
  return 0;

}
