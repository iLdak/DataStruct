#ifndef _TREE_H_ 
#define _TREE_H_ 

typedef void Tree;
typedef void TreeNode;

//������ 
Tree* Tree_Create();

//������ 
void Tree_Destroy(Tree* tree);

//������ϵ����нڵ㣬���˸������ 
void Tree_Clear(Tree* tree);

//��s����ָ��posλ�ò���node��� 
int Tree_Insert(Tree* tree, TreeNode* node, int pos);

//��s����ָ��posλ�ò�ɾ���ڵ㣬�����ؽ��ֵ 
TreeNode* Tree_Delete(Tree* tree, int pos);

//��ȡ����ָ�� posλ���ϵĽ������ 
TreeNode* Tree_Get(Tree* tree, int pos);

//��ȡ����� 
TreeNode* Tree_Root(Tree* tree);

//���ĸ߶� 
int Tree_Height(Tree* tree);

//��ȡ���Ľڵ��� 
int Tree_Count(Tree* tree);

//��ȡ���Ķ� 
int Tree_Degree(Tree* tree);
 
#endif
