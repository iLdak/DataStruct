#include <stdio.h>
#include "StaticList.h"

int main(int argc, char *argv[])
{
	int i = 0;
	
	int a[] = {1,2,3,4,5};
	
	StaticList* list = StaticList_Create(10);
  
	printf("Capacity: %d\n",StaticList_Capacity(list)); 
  	
  	for(i = 0; i < sizeof(a)/sizeof(a[i]); i++)
		StaticList_Insert(list, (StaticListNode*)&a[i], 0);
	
	for(i = 0; i < StaticList_Length(list); i++)
	{
		int* p = (int*)StaticList_Get(list, i);
		printf("taticList_Get%d: %d\n",i,*p);
	}
	
	printf("Length: %d\n",StaticList_Length(list)); 
	
	while(StaticList_Length(list) > 2)
		StaticList_Delete(list, 0);
		
  	printf("Length: %d\n",StaticList_Length(list)); 
  	
  	StaticList_Clear(list);
  	
  	printf("Length: %d\n",StaticList_Length(list));
	printf("Capacity: %d\n",StaticList_Capacity(list));  
  	
	StaticList_Destroy(list);
  
  printf("Press enter to continue ...");
  getchar();	
  return 0;

}
