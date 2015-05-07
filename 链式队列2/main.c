#include <stdio.h>
#include "LinkQueue.h"

int main(int argc, char *argv[])
{
  	int array[10];
	int i = 0;
	
 	LinkQueue* queue = LinkQueue_Create();
 		
 	for(i=0; i<10; i++)
 	{
		array[i] = i+1;
		
		LinkQueue_Append(queue, (void*)(array + i));
	}

	printf("%d\n", *(int*)LinkQueue_Header(queue));
	
	printf("%d\n", (int)LinkQueue_Length(queue));
	
	printf("\n");	
	
	//LinkQueue_Clear(queue);
	
   	for(i=0; i<10; i++)
 	{
		int* addr = (int*)LinkQueue_Departure(queue);
		
		if(addr == NULL)
		{
			printf("%s\n","error");
		}
		else
		{
			printf("%d\n", *addr);
		}
	}
	
	printf("\n");
	
	printf("%d\n", (int)LinkQueue_Length(queue));

  	printf("Press enter to continue ...");
  	getchar();	
  	return 0;

}
