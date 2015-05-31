#ifndef _TREE_H_ 
#define _TREE_H_ 

typedef void GTree;
typedef void GTreeDate;
typedef void (callback)(GTreeDate*);
typedef void (callbackTwo)(GTreeDate* , int);

GTree* GTree_Create();

void GTree_Destroy(GTree* tree);
 
void GTree_Clear(GTree* tree);

int GTree_Insert(GTree* tree, GTreeDate* date, int pos);

GTreeDate* GTree_Delete(GTree* tree, int pos);

GTreeDate* GTree_Get(GTree* tree, int pos);

GTreeDate* GTree_Root(GTree* tree);

int GTree_Height(GTree* tree);

int GTree_Count(GTree* tree);

int GTree_Degree(GTree* tree);

void GTree_Display(GTree* tree, callback* fun, char* div, int number);

int GTree_Search(GTree* tree, GTreeDate* data, callbackTwo* fun);
 
#endif
