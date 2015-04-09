#include <stdio.h>
#include <stdlib.h>
#include "TseqList.h"

int main(int argc, char *argv[])
{
  seqList* list = SeqList_Create(5);
  getchar();
  
  printf("Capacity:%d\n",SeqList_Capacity(list));
  getchar();
  
  printf("Length:%d\n",SeqList_Length(list));
  getchar();
  
  printf("input 1:%d\n",SeqList_Insert(list, "50", 2));
  getchar();
  
  printf("input 2:%d\n",SeqList_Insert(list, "200", 1));
  getchar();
  
  printf("input 3:%d\n",SeqList_Insert(list, "100", 1));
  getchar();
  
  printf("Length:%d\n",SeqList_Length(list));
  getchar();
    
  printf("output 2:%s\n",SeqList_Get(list, 1));
  getchar();
  
  printf("output 1:%s\n",SeqList_Get(list, 0));
  getchar();
  
  printf("output 3:%s\n",SeqList_Get(list, 2));
  getchar();
  
  printf("Delete 2:%s\n",SeqList_Delete(list, 1));
  getchar();
  
  printf("Length:%d\n",SeqList_Length(list));
  getchar();
  
  printf("output 2:%s\n",SeqList_Get(list, 1));
  getchar();
  
  printf("output 1:%s\n",SeqList_Get(list, 0));
  getchar();
  
  SeqList_Clear(list);
  getchar();
  
  printf("Length:%d\n",SeqList_Length(list));
  getchar();
  
  SeqList_Destroy(list);
  
  
  printf("Press enter to continue ...");
  getchar();	
  return 0;

}
