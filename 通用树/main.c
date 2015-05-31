#include <stdio.h>
#include "GTree.h"

void printfDate(GTreeDate* date)
{
	printf("%c\n", (char*)date);
}

void printfDateRelationshipBetween(GTreeDate* date , int flag)
{
	if(flag != 0)
	{
		printf("%c->", (char*)date);
	}
	else
	{
		printf("%c", (char*)date);
	}
	
}

int main(int argc, char *argv[])
{
  GTree *gtree = GTree_Create();
  
  GTree_Insert(gtree, (GTreeDate*)'A', -1);
  GTree_Insert(gtree, (GTreeDate*)'B', 0);
  GTree_Insert(gtree, (GTreeDate*)'C', 0);
  GTree_Insert(gtree, (GTreeDate*)'D', 0);
  GTree_Insert(gtree, (GTreeDate*)'E', 0);
  GTree_Insert(gtree, (GTreeDate*)'F', 1);
  GTree_Insert(gtree, (GTreeDate*)'G', 3);
  
  printf("tree height = %d\n", GTree_Height(gtree));
  
  printf("tree degree = %d\n", GTree_Degree(gtree));
  
  GTree_Display(gtree, printfDate, "+", 2);
  
  printf("\n");
  
  printf("\nlocaltion is: %d\n", GTree_Search(gtree, (GTreeDate*)'G' , printfDateRelationshipBetween));
  
  printf("\n");
  
  GTree_Delete(gtree, 1);
  
  GTree_Display(gtree, printfDate, "+", 2);
  
  GTree_Destroy(gtree);
  
  printf("Press enter to continue ...");
  getchar();	
  return 0;

}
