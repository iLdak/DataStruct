#include <stdio.h>
#include "MGraph.h"

void printf_data(MVertex* v)
{
	if(v != NULL)
	{
		printf("%s", (char*)v);
	}
}

int main(int argc, char *argv[])
{
	MVertex* v[] = {"A", "B", "C", "D", "E", "F"};

	MGraph * graph = MGraph_Create(6, v);
  	
	MGraph_AddEdge(graph, 0, 5, 2);
  	MGraph_AddEdge(graph, 0, 2, 3);
  	MGraph_AddEdge(graph, 0, 1, 3);
  	MGraph_AddEdge(graph, 1, 4, 2);
  	MGraph_AddEdge(graph, 1, 3, 5);
  	
  	MGraph_Display(graph, printf_data);
  	
  	printf("\n");
  	
	MGraph_DFS(graph, 0, printf_data);
  	
  	printf("\n");
  	
	MGraph_BFS(graph, 0, printf_data);
  	
  	printf("\n");

  	printf("graph degree 1:%d\n", MGraph_TD(graph, 1));
  	printf("\n");
  	
  	printf("graph vertex conut:%d\n", MGraph_VertexCount(graph));
  	printf("\n");
  	
  	printf("graph Edge count:%d\n", MGraph_EdgeCount(graph));
  	printf("\n");
  	
  	printf("remove edge A-->B w:%d\n",MGraph_RemoveEdge(graph,0, 1));
  	printf("\n");
  	
  	printf("after remove edge A-->B ...\n");
  	MGraph_Display(graph, printf_data);
  	printf("\n");
  	
  	printf("after clear graph ...\n");
  	MGraph_Clear(graph);
  	MGraph_Display(graph, printf_data);
  	
 	printf("graph degree 1:%d\n", MGraph_TD(graph, 1));;
  	
  	printf("graph vertex conut:%d\n", MGraph_VertexCount(graph));
  	
  	printf("graph Edge count:%d\n", MGraph_EdgeCount(graph));
  
	MGraph_Destroy(graph);
  
	printf("Press enter to continue ...");
 	getchar();	
 	return 0;

}
