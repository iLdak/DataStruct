#include <stdio.h>
#include "TseqList.h"
#include "BTree.h"

struct Node
{
    BTreeNode header;
    char v;
};

void printf_data(BTreeNode* node)
{
    if( node != NULL )
    {
        printf("%c", ((struct Node*)node)->v);
        printf("\n");
    }
}

void thread_via_left(BTreeNode* root, BTreeNode** pp)
{
    if( (root != NULL) && (pp != NULL) )
    {
        if( *pp != NULL )
        {
            (*pp)->left = root;
            *pp = NULL;
        }
        
        if( root->left == NULL )
        {
            *pp = root;
        }
        
        thread_via_left(root->left, pp);
        thread_via_left(root->right, pp);
    }
}

void thread_via_list(seqList* list, BTreeNode* node)
{
    if( (list != NULL) && (node != NULL) )
    {
		SeqList_Insert(list, node, SeqList_Length(list));
		
        thread_via_list(list, node->left);
        thread_via_list(list, node->right);
    }
}

int main(int argc, char *argv[])
{
    BTree* tree = BTree_Create();
    BTreeNode* current = NULL;
    BTreeNode* p = NULL;
    int i = 0;
    seqList* list = NULL;
    
    struct Node n1 = {{NULL, NULL}, 'A'};
    struct Node n2 = {{NULL, NULL}, 'B'};
    struct Node n3 = {{NULL, NULL}, 'C'};
    struct Node n4 = {{NULL, NULL}, 'D'};
    struct Node n5 = {{NULL, NULL}, 'E'};
    struct Node n6 = {{NULL, NULL}, 'F'};
    
    BTree_Insert(tree, (BTreeNode*)&n1, 0, 0, 0);
    BTree_Insert(tree, (BTreeNode*)&n2, 0x00, 1, 0);
    BTree_Insert(tree, (BTreeNode*)&n3, 0x01, 1, 0);
    BTree_Insert(tree, (BTreeNode*)&n4, 0x00, 2, 0);
    BTree_Insert(tree, (BTreeNode*)&n5, 0x02, 2, 0);
    BTree_Insert(tree, (BTreeNode*)&n6, 0x02, 3, 0);
    
    printf("Full Tree: \n");
    
    BTree_Display(tree, printf_data, 4, '-');
    
    printf("Thread via list:\n");
    
    list = SeqList_Create(BTree_Count(tree));
    
    thread_via_list(list, BTree_Root(tree));
    
    for(i = 0; i < SeqList_Length(list); i++)
    {
		printf("%c, ", ((struct Node*)SeqList_Get(list, i))->v);
	}
	
	printf("\n");
    
    printf("Thread via Left:\n");
    
    current = BTree_Root(tree);
    
    thread_via_left(current, &p);
    
    while( current != NULL )
    {
        printf("%c, ", ((struct Node*)current)->v);
        
        current = current->left;
    }
    
    printf("\n");
    
    BTree_Destroy(tree);
    
	printf("Press enter to continue ...");
	getchar();	
	return 0;
}
