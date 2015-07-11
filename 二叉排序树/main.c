#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"

struct Node{
	BSTreeNode node;
	char c;
};

void printfDate(BSTreeNode* node)
{
	if(node != NULL)
	{
		printf("%c\n", ((struct Node*)node)->c);
	}

}

int Comparison(BSKey* key1, BSKey* key2)
{
	int ret;
	
	return (int)key1 - (int)key2;
}

int main(int argc, char *argv[])
{
  	BSTree* tree = BSTree_Create();
  
  	struct Node v1 = {{1, NULL, NULL}, 'A'};;
  	struct Node v2 = {{2, NULL, NULL}, 'B'};;
  	struct Node v3 = {{3, NULL, NULL}, 'C'};;
  	struct Node v4 = {{4, NULL, NULL}, 'D'};;
  	struct Node v5 = {{5, NULL, NULL}, 'E'};;
  	struct Node v6 = {{6, NULL, NULL}, 'F'};;
  	struct Node* mnode = NULL;

 	BSTree_Insert(tree, (BSTreeNode*)&v3,Comparison);
	BSTree_Insert(tree, (BSTreeNode*)&v1,Comparison);
  	BSTree_Insert(tree, (BSTreeNode*)&v5,Comparison);
  	BSTree_Insert(tree, (BSTreeNode*)&v2,Comparison);
 	BSTree_Insert(tree, (BSTreeNode*)&v6,Comparison);
  	BSTree_Insert(tree, (BSTreeNode*)&v4,Comparison);

  
  
  	printf("Full BSTree Height:%d\n",BSTree_Height(tree));
  
  	printf("Full BSTree node count:%d\n",BSTree_Count(tree));
  
  	printf("BSTree degree:%d\n",BSTree_Degree(tree));

  	printf("Full BSTree:\n");
  	BSTree_Display(tree, printfDate, 2, '-');
  
  	mnode = BSTree_Delete(tree, 3, Comparison);
  	if(mnode != NULL)
  		printf("Delete 1 After:\n",mnode->c);
  
  	BSTree_Display(tree, printfDate, 2, '-');
  
  	mnode = ((struct Node*)BSTree_Get(tree, 1, Comparison));
  	if(mnode != NULL)
		printf("get 1 node:%c\n", mnode->c);
  
  	BSTree_Destroy(tree);
  
  	printf("Press enter to continue ...");
  	getchar();	
  	return 0;

}
