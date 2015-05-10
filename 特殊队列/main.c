#include <stdio.h>
#include "SQueue.h"

int main(int argc, char *argv[])
{
	
  	int array[10];
	int i = 0;
	
 	SQueue* queue = SQueue_Create();
 		
 	for(i=0; i<10; i++)
 	{
		array[i] = i+1;
		
		SQueue_Append(queue, (void*)(array + i));
	}

	printf("%d\n", *(int*)SQueue_Header(queue));
	
	printf("%d\n", (int)SQueue_Length(queue));
	
	printf("\n");	
	
	//SQueue_Clear(queue);
	
   	for(i=0; i<5; i++)
 	{
		int* addr = (int*)SQueue_Departure(queue);
		
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
	
	printf("%d\n", (int)SQueue_Length(queue));
	
	for(i=0; i<10; i++)
 	{
		array[i] = i+1;
		
		SQueue_Append(queue, (void*)(array + i));
	}
	getchar();
	printf("%d\n", *(int*)SQueue_Header(queue));
	
	printf("%d\n", (int)SQueue_Length(queue));
	
	printf("\n");
	
	while(SQueue_Length(queue))
	{
		int* addr = (int*)SQueue_Departure(queue);
		
		if(addr == NULL)
		{
			printf("%s\n","error");
		}
		else
		{
			printf("%d\n", *addr);
		}
	}

	if(SQueue_Header(queue) != NULL)
		printf("%d\n", *(int*)SQueue_Header(queue));
	else
	{
		printf("queue is null\n");
	}

	printf("%d\n", (int)SQueue_Length(queue));

	printf("\n");

	SQueue_Departure(queue);

  	printf("Press enter to continue ...");
  	getchar();	
  	return 0;
}
