#include <stdio.h>
#include "MGraph.h"
#include <malloc.h>
#include "LinkQueue.h"

typedef struct _tag_MGraph
{
	int count;
	MVertex** v;
    int** matrix;
} TMGraph;

static void recursive_dfs(MGraph* graph, int v, printf_vertices* pFunc, int* visited)
{
	TMGraph* gra = (TMGraph*)graph;
	
	int i = 0;
	
	pFunc(gra->v[v]);
	
	visited[v] = 1;
	
	printf(", ");

	for(i = 0; i < gra->count; i++)
	{
		if( gra->matrix[v][i] != 0 && visited[i] == 0 )
		{
			recursive_dfs(graph, i, pFunc, visited);	
		}
	}	
}

static void bfs(MGraph* graph, int v, printf_vertices* pFunc, int* visited)
{
	TMGraph* gra = (TMGraph*)graph;
	
	LinkQueue* queue = LinkQueue_Create(); 
	
	if( queue != NULL )
	{
		int v2 = 0;
		
		int i = 0;
		
		LinkQueue_Append(queue, gra->v + v);
		
		while( LinkQueue_Length(queue) )
		{
			v2 = (MVertex**)LinkQueue_Departure(queue) - (gra->v); 
			
			pFunc(gra->v[v2]);
	
			visited[v2] = 1;
	
			printf(", ");
			
			for(i = 0; i < gra->count; i++)
			{
				if( gra->matrix[v2][i] != 0 && visited[i] == 0 )
				{
					LinkQueue_Append(queue, gra->v + i);
				}
			}
		}
	}
}

MGraph* MGraph_Create(int n, MVertex** v)//O(n)
{
	TMGraph* ret = NULL;
	
	if( (n > 0) && (v != NULL) )
	{
		ret = (TMGraph*)malloc(sizeof(TMGraph));
		
		if(ret != NULL)
		{
			int* p;
			ret->count = n;
			ret->v = (MVertex**)malloc(sizeof(MVertex*) * n);
			ret->matrix = (int **)malloc(sizeof(int*) * n);
			p = (int *)calloc( n * n, sizeof(int));
			
			if( (p != NULL) && (ret->count > 0) && (ret->v != NULL) && (ret->matrix != NULL) )
			{
				int i =0;
				
				for(i = 0; i < ret->count; i++)
				{
					ret->v[i] = v[i];
					ret->matrix[i] = p + i * n;
				}
			}
			else
			{
				free(p);
				free(ret->matrix);
				free(ret->v);
				free(ret);
				ret = NULL;
			}
		}
	}	
	
	return ret;
}

void MGraph_Destroy(MGraph* graph)//O(0)
{
	TMGraph* gra = (TMGraph*)graph;
	
	if( gra != NULL )
	{
		free(gra->v);
		free(gra->matrix[0]);
		free(gra->matrix);
		free(gra);
	}
}

void MGraph_Clear(MGraph* graph)//O(n * n)
{
	TMGraph* gra = (TMGraph*)graph;
	
	if( gra != NULL )
	{
		int i, j;
		
		for( i = 0; i < gra->count; i++ )
		{
			for( j = 0; j < gra->count; j++ )
			{
				gra->matrix[i][j] = 0;
			}
		}
	}
}

int MGraph_AddEdge(MGraph* graph, int v1, int v2, int w)//O(0)
{
	TMGraph* gra = (TMGraph*)graph;
	
	int ret = (gra != NULL);
	
	ret = ret && ( 0 <= v1 ) && ( v1 < gra->count );
	
	ret = ret && ( 0 <= v2 ) && ( v2 < gra->count );
	
	ret = ret && ( 0 < w );
	
	if( ret )
	{
		gra->matrix[v1][v2] = w;
	}
	
	return ret;
}

int MGraph_RemoveEdge(MGraph* graph,int v1, int v2)//O(n)
{
	int ret = MGraph_GetEdge(graph, v1, v2);
	
	if( ret )
	{
		((TMGraph*)graph)->matrix[v1][v2] = 0;
	}
	
	return ret;
}

int MGraph_GetEdge(MGraph* graph,int v1, int v2)//O(0)
{
	TMGraph* gra = (TMGraph*)graph;
	
	int ret = 0;
	
	int condition = (gra != NULL);
	
	condition = condition && ( 0 <= v1 ) && ( v1 < gra->count );
	
	condition = condition && ( 0 <= v2 ) && ( v2 < gra->count );
	
	if( condition )
	{
		ret = gra->matrix[v1][v2];
	}
	
	return ret;
}

int MGraph_TD(MGraph* graph, int v)//O(n)
{
	TMGraph* gra = (TMGraph*)graph;
	
	int ret = (gra != NULL);
	
	ret = ret && (0 <= v) && (v < gra->count);
	
	if( ret )
	{
		int i = 0;
		
		ret = 0;
		
		for(i = 0; i < gra->count; i++)
		{
			if(gra->matrix[v][i] != 0)
			{
				ret++;
			}
			
			if(gra->matrix[i][v] != 0)
			{
				ret++;
			}
		}
	}
	
	return ret;
}

int MGraph_VertexCount(MGraph* graph)//O(0)
{
	TMGraph* gra = (TMGraph*)graph;
	
	int ret = 0;
	
	if( gra != NULL )
	{
		ret = gra->count;
	}
	return ret;
}

int MGraph_EdgeCount(MGraph* graph)//O(n * n)
{
	TMGraph* gra = (TMGraph*)graph;
	
	int ret = 0;
	
	if( gra != NULL )
	{
		int i, j;
		
		for( i = 0; i < gra->count; i++ )
		{
			for( j = 0; j < gra->count; j++ )
			{
				if(gra->matrix[i][j] != 0)
				{
					ret++;
				}
			}
		}
	}
	
	return ret;
}

void MGraph_DFS(MGraph* graph, int v, printf_vertices* pFunc)
{
	TMGraph* gra = (TMGraph*)graph;
	
	int condition = (gra != NULL);
	
	condition = condition && ( 0 <= v ) && ( v < gra->count );
	
	condition = condition && (pFunc != NULL);
	
	if( condition )
	{
		int* visited = (int*)calloc(gra->count ,sizeof(int));
		
		int i = 0;
		
		recursive_dfs(graph, 0, pFunc, visited);
		
		for(i = 0; i < gra->count; i++)
		{
			if(visited[i] == 0)
			{
				recursive_dfs(graph, i, pFunc, visited);	
			}
		}
		
		printf("\n");
	}
}

void MGraph_BFS(MGraph* graph, int v, printf_vertices* pFunc)
{
	TMGraph* gra = (TMGraph*)graph;
	
	int condition = (gra != NULL);
	
	condition = condition && ( 0 <= v ) && ( v < gra->count );
	
	condition = condition && (pFunc != NULL);
	
	if( condition )
	{
		int* visited = (int*)calloc(gra->count ,sizeof(int));
		
		int i = 0;
		
		bfs(graph, 0, pFunc, visited);
		
		for(i = 0; i < gra->count; i++)
		{
			if(visited[i] == 0)
			{
				bfs(graph, i, pFunc, visited);	
				printf("00123\n");
			}
		}
		
		printf("\n");
	}
}

void MGraph_Display(MGraph* graph, printf_vertices* pFunc) //O(n * n)
{
	TMGraph* gra = (TMGraph*)graph;
	
	if( (gra != NULL) && (pFunc != NULL) )
	{
		int i = 0;
		int j = 0;
		
		for(i = 0; i < gra->count; i++)
		{	
			printf("%d:",i);
			pFunc(gra->v[i]);
			printf(" ");
		}
		
		printf("\n");
		
		for(i = 0; i < gra->count; i++)
		{
			for(j = 0; j < gra->count; j++)
			{
				if(gra->matrix[i][j] != 0)
				{
					printf("<");
					pFunc(gra->v[i]);
					printf(",");
					pFunc(gra->v[j]);
					printf(",");
					printf("%d",gra->matrix[i][j]);
					printf(">");
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}

