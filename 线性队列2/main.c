#include <stdio.h>
#include "SeqQueue.h"

int main(int argc, char *argv[])
{
	int array[10];
	int i = 0;
	
 	SeqQueue* queue = SeqQueue_Create(6);
 		
 	for(i=0; i<10; i++)
 	{
		array[i] = i+1;
		
		SeqQueue_Append(queue, (void*)(array + i));
	}
	
	printf("%d\n", *(int*)SeqQueue_Header(queue));
	printf("%d\n", (int)SeqQueue_Length(queue));
	printf("\n");
	
	for(i=0; i<10; i++)
 	{
		int* addr = (int*)SeqQueue_Departure(queue);
		
		if(addr == NULL)
		{
			printf("%s\n", "error");
		}
		else
		{
			printf("%d\n", *addr);		
		}

	}
	printf("\n");
	printf("%d\n", (int)SeqQueue_Length(queue));
	printf("%d\n", (int)SeqQueue_Capacity(queue));
	printf("\n");
	
 	for(i=0; i<10; i++)
 	{
		array[i] = i+1;
		
		SeqQueue_Append(queue, (void*)(array + i));
		
		printf("%d\n", *(int*)SeqQueue_Departure(queue));
	}
	
 	SeqQueue_Destroy(queue);
 	printf("Press enter to continue ...");
  	getchar();	
  	return 0;
}
