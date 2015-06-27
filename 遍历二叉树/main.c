#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"
#include "LinkQueue.h"

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

void pre_order_traverse(BTreeNode* node)
{
	if(node != NULL)
	{
		printf("%c ", ((struct Node*)node)->c);
		
		pre_order_traverse(node->left);
		
		pre_order_traverse(node->right);
	}
}

void middle_order_traverse(BTreeNode* node)
{
	if(node != NULL)
	{
		middle_order_traverse(node->left);
		
		printf("%c ", ((struct Node*)node)->c);
		
		middle_order_traverse(node->right);
	}
}

void level_order_traverse(BTreeNode* node)
{
	if(node != NULL)
	{
		LinkQueue* queue =  LinkQueue_Create();
		
		LinkQueue_Append(queue, node);
		
		while(LinkQueue_Length(queue) > 0)
		{
			struct Node * getNode = (struct Node*)LinkQueue_Departure(queue);
			
			printf("%c ", ((struct Node*)getNode)->c);
			
			LinkQueue_Append(queue, getNode->node.left);
			
			LinkQueue_Append(queue, getNode->node.right);
		}
		
		LinkQueue_Destroy(queue);
	}
}

void post_order_traverse(BTreeNode* node)
{
	if(node != NULL)
	{
		post_order_traverse(node->left);
		
		post_order_traverse(node->right);
		
		printf("%c ", ((struct Node*)node)->c);
	}
}

int main(int argc, char *argv[])
{
  BTree* tree = BTree_Create();
  
  struct Node v1 = {{NULL, NULL}, 'A'};;
  struct Node v2 = {{NULL, NULL}, 'B'};;
  struct Node v3 = {{NULL, NULL}, 'C'};;
  struct Node v4 = {{NULL, NULL}, 'D'};;
  struct Node v5 = {{NULL, NULL}, 'E'};;
  struct Node v6 = {{NULL, NULL}, 'F'};;
  struct Node* mnode = NULL;

  BTree_Insert(tree, (BTreeNode*)&v1, 0, 0, 0);
  BTree_Insert(tree, (BTreeNode*)&v2, 0x00, 1, BT_LEFT);
  BTree_Insert(tree, (BTreeNode*)&v3, 0x01, 1, BT_RIGHT);
  BTree_Insert(tree, (BTreeNode*)&v4, 0x00, 2, BT_LEFT);
  BTree_Insert(tree, (BTreeNode*)&v5, 0x00, 3, BT_LEFT);
  BTree_Insert(tree, (BTreeNode*)&v6, 0x00, 4, BT_LEFT);
  
  printf("Full BTree Height:%d\n",BTree_Height(tree));
  
  printf("Full BTree node count:%d\n",BTree_Count(tree));
  
  printf("BTree degree:%d\n",BTree_Degree(tree));

  printf("Full BTree:\n");
  BTree_Display(tree, printfDate, 2, '-');
  
  printf("Pre Order Traverse BTree:\n");
  pre_order_traverse(BTree_Root(tree));
  printf("\n");
  
  printf("Middle Order Traverse BTree:\n");
  middle_order_traverse(BTree_Root(tree));
  printf("\n");
  
  printf("Post Order Traverse BTree:\n");
  post_order_traverse(BTree_Root(tree));
  printf("\n");
  
  printf("Level Order Traverse BTree:\n");
  level_order_traverse(BTree_Root(tree));
  printf("\n");
  
  printf("Delete B After:\n");
  BTree_Delete(tree, 0x00, 1);
  BTree_Display(tree, printfDate, 2, '-');
  
  mnode = ((struct Node*)BTree_Get(tree, 0x01, 1));
  if(mnode != NULL)
	printf("get C node:%c\n", mnode->c);
  
  BTree_Destroy(tree);
  
  printf("Press enter to continue ...");
  getchar();	
  return 0;

}
