#include <stdio.h>
#include "LinkList.h"

typedef struct
{
	LinkListNode header;
	int value;
}Value;

int main(int argc, char *argv[])
{
	int i = 0;
	
	//创建 
	LinkList* list = LinkList_Create();
		
	LinkList_Clear(list);
	
	Value v1;
	Value v2;
	Value v3;
	Value v4;
	Value v5;

	v1.value = 1;
	v2.value = 2;
	v3.value = 3;
	v4.value = 4;
	v5.value = 5;

	LinkList_Insert(list, (LinkListNode*)&v1, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode*)&v2, LinkList_Length(list));	
	LinkList_Insert(list, (LinkListNode*)&v3, LinkList_Length(list));	
	LinkList_Insert(list, (LinkListNode*)&v4, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode*)&v5, LinkList_Length(list));

	

	for(i = 0; i < LinkList_Length(list); i++)
	{
		Value* pv = (Value*)LinkList_Get(list,i);
		
		printf("%d\n",pv->value);
	}
	
	for(; LinkList_Length(list) > 0;)
	{
		Value* pv = (Value*)LinkList_Delete(list,0);
		
		printf("%d\n",pv->value);
	}
	
	//释放空间 
	LinkList_Destroy(list);

	printf("Press enter to continue ...");
	getchar();	
	return 0;

}
