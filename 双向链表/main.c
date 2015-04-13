#include <stdio.h>
#include "DLinkList.h"
typedef struct _tag_data_struct
{
	DLinkListNode header;
	int v;
}data_struct;

int main(int argc, char *argv[])
{
	int i = 0;
	data_struct* pv;
	
	data_struct v1;
	data_struct v2;
	data_struct v3;
	data_struct v4;
	data_struct v5;
	data_struct v6;
	
	v1.v =1;
	v2.v =2;
 	v3.v =3;
	v4.v =4;
	v5.v =5;
	v6.v =6;
	
	//creat link list
	DLinkList* list = DLinkList_Create();
	
	//insert node data
 	DLinkList_Insert(list, (DLinkListNode*)&v1,0);
	DLinkList_Insert(list, (DLinkListNode*)&v2,0);
	DLinkList_Insert(list, (DLinkListNode*)&v3,0);
	DLinkList_Insert(list, (DLinkListNode*)&v4,0);
	DLinkList_Insert(list, (DLinkListNode*)&v5,0);
	DLinkList_Insert(list, (DLinkListNode*)&v6,0);
	
	//print node data
	for(i = 0; i < DLinkList_Length(list); i++)
	{
		pv = (data_struct*)DLinkList_Get(list, i);
		printf("%d  ",pv->v);
	}
	
  	printf("\n");
  	printf("\n");
	
	//delete node data
	i = 0;
	while(DLinkList_Length(list))
	{
		pv = (data_struct*)DLinkList_Delete(list, DLinkList_Length(list) - 1);
		printf("%d  ",pv->v);
		i++;
	} 

	printf("\n");
	printf("\n");
	
	//insert node data
 	DLinkList_Insert(list, (DLinkListNode*)&v1,0);
	DLinkList_Insert(list, (DLinkListNode*)&v2,0);
	DLinkList_Insert(list, (DLinkListNode*)&v3,0);
	DLinkList_Insert(list, (DLinkListNode*)&v4,0);
	DLinkList_Insert(list, (DLinkListNode*)&v5,0);
	DLinkList_Insert(list, (DLinkListNode*)&v6,0);
	
	pv = (data_struct*)DLinkList_DeleteNode(list, (DLinkListNode*)&v2);
	printf("%d\n",pv->v);
	pv = (data_struct*)DLinkList_DeleteNode(list, (DLinkListNode*)&v1);
	printf("%d\n",pv->v);
	pv = (data_struct*)DLinkList_DeleteNode(list, (DLinkListNode*)&v6);
	printf("%d\n",pv->v);
	
	printf("\n");
	
	pv = (data_struct*)DLinkList_Reset(list);
	printf("%d\n",pv->v);
	
	printf("\n");
	
	pv = (data_struct*)DLinkList_Current(list);
	printf("%d\n",pv->v);
	
	printf("\n");
	
	pv = (data_struct*)DLinkList_Next(list);
	printf("%d\n",pv->v);
	pv = (data_struct*)DLinkList_Current(list);
	printf("%d\n",pv->v);
	
	printf("\n"); 
	
	pv = (data_struct*)DLinkList_Per(list);
	printf("%d\n",pv->v);
	pv = (data_struct*)DLinkList_Current(list);
	printf("%d\n",pv->v);
	
	printf("\n");
	
  	//destroy link list
  	DLinkList_Destroy(list);
  
  	printf("Press enter to continue ...");
  	getchar();	
  	return 0;

}
