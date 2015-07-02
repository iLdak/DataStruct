#include <stdio.h>
#include "LGraph.h"
#include "LinkQueue.h"

void printf_data(LVertex* v)
{
	if(v != NULL)
	{
		printf("%s", (char*)v);
	}
}

int main(int argc, char *argv[])
{
	LVertex* v[] = {"A", "B", "C", "D", "E", "F"};

	LGraph * graph = LGraph_Create(6, v);
  

  	LGraph_AddEdge(graph, 0, 1, 2);
  	LGraph_AddEdge(graph, 0, 2, 3);
  	LGraph_AddEdge(graph, 0, 5, 3);
  	LGraph_AddEdge(graph, 5, 4, 2);
  	LGraph_AddEdge(graph, 5, 3, 5);

  	LGraph_Display(graph, printf_data);
  	
  	printf("\n");
  	
  	LGraph_DFS(graph, 0, printf_data);
  	
  	printf("\n");
  	
	LGraph_BFS(graph, 0, printf_data);
  	
  	printf("\n");
  	
  	printf("graph degree 1:%d\n", LGraph_TD(graph, 1));
  	printf("\n");
  	
  	printf("graph vertex conut:%d\n", LGraph_VertexCount(graph));
  	printf("\n");
  	
  	printf("graph Edge count:%d\n", LGraph_EdgeCount(graph));
  	printf("\n");
  	
  	printf("remove edge A-->B w:%d\n",LGraph_RemoveEdge(graph,0, 1));
  	printf("\n");
  	
  	printf("after remove edge A-->B ...\n");
  	LGraph_Display(graph, printf_data);
  	printf("\n");
  	
  	printf("after clear graph ...\n");
  	LGraph_Clear(graph);
  	LGraph_Display(graph, printf_data);
  	
 	printf("graph degree 1:%d\n", LGraph_TD(graph, 1));;
  	
  	printf("graph vertex conut:%d\n", LGraph_VertexCount(graph));
  	
  	printf("graph Edge count:%d\n", LGraph_EdgeCount(graph));
  
	LGraph_Destroy(graph);

	printf("Press enter to continue ...");
	getchar();	
	return 0;

}
