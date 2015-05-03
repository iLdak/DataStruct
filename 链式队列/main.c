#include <stdio.h>
#include "LinkQueue.h"

int main(int argc, char *argv[])
{
  	int array[10];
	int i = 0;
	
 	LinkQueue* queue = LinkQueue_Create(20);
 		
 	for(i=0; i<10; i++)
 	{
		array[i] = i+1;
		
		LinkQueue_Append(queue, (void*)array[i]);
	}

	printf("%d\n", (int)LinkQueue_Header(queue));
	
	printf("%d\n", (int)LinkQueue_Length(queue));
		
   	for(i=0; i<10; i++)
 	{
		array[i] = i+1;
		
		printf("%d\n", (int)LinkQueue_Departure(queue));
	}
	
	printf("%d\n", (int)LinkQueue_Length(queue));

  	printf("Press enter to continue ...");
  	getchar();	
  	return 0;

}
