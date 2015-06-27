#include <stdio.h>
#include "Graph.h"

int main(int argc, char *argv[])
{
  Graph * graph = Graph_Create(5);
  
  
  
  Graph_Destroy(graph);
  
  printf("Press enter to continue ...");
  getchar();	
  return 0;

}
