#ifndef _TREE_H_ 
#define _TREE_H_ 

typedef void Tree;
typedef void TreeNode;

//创建树 
Tree* Tree_Create();

//销毁树 
void Tree_Destroy(Tree* tree);

//清除树上的所有节点，除了根结点外 
void Tree_Clear(Tree* tree);

//在s树上指定pos位置插入node结点 
int Tree_Insert(Tree* tree, TreeNode* node, int pos);

//在s树上指定pos位置插删除节点，并返回结点值 
TreeNode* Tree_Delete(Tree* tree, int pos);

//获取树上指定 pos位置上的结点数据 
TreeNode* Tree_Get(Tree* tree, int pos);

//获取根结点 
TreeNode* Tree_Root(Tree* tree);

//树的高度 
int Tree_Height(Tree* tree);

//获取树的节点数 
int Tree_Count(Tree* tree);

//获取树的度 
int Tree_Degree(Tree* tree);
 
#endif
