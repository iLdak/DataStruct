#include <stdio.h>
#include "LinkStack.h"

int main(int argc, char *argv[])
{
	LinkStack* stack = LinkStack_Creat();
    int a[10];
    int i = 0;
    
    for(i=0; i<10; i++)
    {
        a[i] = i;
        
        LinkStack_Push(stack, a + i);
    }
    
    printf("Top: %d\n", *(int*)LinkStack_Top(stack));
    printf("Length: %d\n", LinkStack_Size(stack));
    //LinkStack_Clear(stack);
    
    while( LinkStack_Size(stack) > 0 )
    {
        printf("Pop: %d\n", *(int*)LinkStack_Pop(stack));
    }
    
    LinkStack_Destroy(stack);
  printf("Press enter to continue ...");
  getchar();	
  return 0;

}
