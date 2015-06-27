#include <stdio.h>
#include "LGraph.h"
#include <malloc.h>
#include "LinkList.h"
#include "LinkQueue.h"

typedef struct _tag_LGraph
{
	int count;
	LVertex** v;
    LinkList** la;
} TLGraph;

typedef struct _tag_LGraphLinkListNode
{
	LinkListNode* header;
	int v;
	int w;
} LGraphLinkListNode;

static void recursive_dfs(LGraph* graph, int v, printf_vertices* pFunc, int* visited)
{
	TLGraph* gra = (TLGraph*)graph;
	
	int i = 0;
	
	LGraphLinkListNode* node = NULL;
	
	pFunc(gra->v[v]);
	
	visited[v] = 1;
	
	printf(", ");

	for(i = 0; i < LinkList_Length(gra->la[v]); i++)
	{
		node = (LGraphLinkListNode*)LinkList_Get(gra->la[v], i);
		
		if( visited[node->v] == 0 )
		{
			recursive_dfs(graph, node->v, pFunc, visited);	
		}
	}	
}

static void bfs(LGraph* graph, int v, printf_vertices* pFunc, int* visited)
{
	TLGraph* gra = (TLGraph*)graph;
	
	LGraphLinkListNode* node = NULL;
	
	LinkQueue* queue = LinkQueue_Create(); 
	
	if( queue != NULL )
	{
		int v2 = 0;
		
		int i = 0;
		
		LinkQueue_Append(queue, gra->v + v);
		
		while( LinkQueue_Length(queue) )
		{
			v2 = (LVertex**)LinkQueue_Departure(queue) - (gra->v); 
			
			pFunc(gra->v[v2]);
	
			visited[v2] = 1;
	
			printf(", ");
			
			for(i = 0; i < LinkList_Length(gra->la[v2]); i++)
			{
				node = LinkList_Get(gra->la[v2], i);
				
				if( visited[node->v] == 0 )
				{
					LinkQueue_Append(queue, gra->v + node->v);
				}
			}
		}
	}
}

LGraph* LGraph_Create(int n, LVertex** v)//O(n)
{
	TLGraph* ret = NULL;
	
	int flag = (n > 0) && (v != NULL);
	
	if( flag )
	{
		ret = (TLGraph*)malloc(sizeof(TLGraph));
		
		if(ret != NULL)
		{
			ret->count = n;
			ret->v = (LVertex**)calloc(n, sizeof(LVertex*));
			ret->la = (LinkList**)calloc(n, sizeof(LinkList*));
			
			if( (ret->count > 0) && (ret->v != NULL) && (ret->la != NULL) )
			{
				int i =0;
				
				for(i = 0; i < ret->count; i++)
				{
					ret->v[i] = v[i];
				}
				
				for(i = 0; i < ret->count && flag; i++)
				{
					flag = flag && ((ret->la[i] = LinkList_Create()) != NULL);
				}
			}
			
			if( flag == NULL )
			{
				if(ret->la !=  NULL)
				{
					int i = 0;
				
					for(i = 0; i < i < ret->count; i++)
					{
						free(ret->la[i]);
					}	
				}
				
				free(ret->la);
				free(ret->v);
				free(ret);
				ret = NULL;
			}
		}
	}	
	
	return ret;
}

void LGraph_Destroy(LGraph* graph)//O(n)
{
	TLGraph* gra = (TLGraph*)graph;
	
 	LGraph_Clear(graph);
 	
	if( gra != NULL )
	{
		int i = 0;
	 
	 	for(i = 0; i < gra->count; i++)
	 	{
			LinkList_Destroy(gra->la[i]);
			//free(gra->la[i]);
		}
		
		free(gra->la);
		free(gra->v);
		free(gra);
	}
}

void LGraph_Clear(LGraph* graph)//O(n * n)
{
	TLGraph* gra = (TLGraph*)graph;
	
	if( gra != NULL )
	{
		int i, j;
		
		for(i = 0; i < gra->count; i++)
		{
			while( LinkList_Length(gra->la[i]) )
			{
				free(LinkList_Delete(gra->la[i], 0));
			}
		}
	}
}

int LGraph_AddEdge(LGraph* graph, int v1, int v2, int w)//O(n * n)
{
	TLGraph* gra = (TLGraph*)graph;
	
	LGraphLinkListNode* graLinkListNode = NULL;
	
	int ret = (gra != NULL);
	
	ret = ret && ( 0 <= v1 ) && ( v1 < gra->count );
	
	ret = ret && ( 0 <= v2 ) && ( v2 < gra->count );
	
	ret = ret && ( 0 < w ) && ((graLinkListNode = (LGraphLinkListNode*)malloc(sizeof(LGraphLinkListNode))) != NULL);
	
	if( ret )
	{
		
		int i = 0;
		int flag = 1;
		
		LGraphLinkListNode* node = NULL;
		
		for(i = 0; i < LinkList_Length(gra->la[v1]); i++)
		{
			node = (LGraphLinkListNode*)LinkList_Get(gra->la[v1], i);
			
			if( node->v == v2 )
			{
				node->w = w;
				
				flag = 0;
				
				free(graLinkListNode);
				
				ret = 1; 
				
				break;
			}
		}
		
		if( flag )
		{
			graLinkListNode->w = w;
			graLinkListNode->v = v2;
		
			LinkList_Insert(gra->la[v1], graLinkListNode, 0);
		}
	}
	
	return ret;
}

int LGraph_RemoveEdge(LGraph* graph,int v1, int v2)//O(n * n)
{
	TLGraph* gra = (TLGraph*)graph;
	
	int ret = 0;
	
	int condition = (gra != NULL);
	
	condition = condition && ( 0 <= v1 ) && ( v1 < gra->count );
	
	condition = condition && ( 0 <= v2 ) && ( v2 < gra->count );
	
	if( condition )
	{
		int i = 0;
		
		LGraphLinkListNode* node = NULL;
		
		for(i = 0; i < LinkList_Length(gra->la[v1]); i++)
		{
			node = (LGraphLinkListNode*)LinkList_Get(gra->la[v1], i);
			
			if( node->v == v2 )
			{
				ret = node->w;
								
				LinkList_Delete(gra->la[v1], i);
				
				free(node);
				
				break;
			}
		}
	}
	
	return ret;
}

int LGraph_GetEdge(LGraph* graph,int v1, int v2)//O(n * n)
{
	TLGraph* gra = (TLGraph*)graph;
	
	int ret = 0;
	
	int condition = (gra != NULL);
	
	condition = condition && ( 0 <= v1 ) && ( v1 < gra->count );
	
	condition = condition && ( 0 <= v2 ) && ( v2 < gra->count );
	
	if( condition )
	{
		int i = 0;
		
		LGraphLinkListNode* node = NULL;
		
		for(i = 0; i < LinkList_Length(gra->la[v1]); i++)
		{
			node = (LGraphLinkListNode*)LinkList_Get(gra->la[v1], i);
			
			if( node->v == v2 )
			{
				ret = node->w;
				
				break;
			}
		}
	}
	
	return ret;
}

int LGraph_TD(LGraph* graph, int v)//O(n * n * n)
{
	TLGraph* gra = (TLGraph*)graph;
	
	int ret = (gra != NULL);
	
	ret = ret && (0 <= v) && (v < gra->count);
	
	if( ret )
	{
		int i, j = 0;
		
		ret = 0;
		
		LGraphLinkListNode* node = NULL;
		
		for(i = 0; i < gra->count; i++)
		{
			for(j = 0; j < LinkList_Length(gra->la[i]); j++)
			{
				node = (LGraphLinkListNode*)LinkList_Get(gra->la[i], j);
				
				if( node->v == v )
				{
					ret++;
				}
			}
		}
		
		ret += LinkList_Length(gra->la[v]);
	}
	
	return ret;
}

int LGraph_VertexCount(LGraph* graph)//O(0)
{
	TLGraph* gra = (TLGraph*)graph;
	
	int ret = 0;
	
	if( gra != NULL )
	{
		ret = gra->count;
	}
	return ret;
}

int LGraph_EdgeCount(LGraph* graph)//O(n)
{
	TLGraph* gra = (TLGraph*)graph;
	
	int ret = 0;
	
	if( gra != NULL )
	{
		int i, j;
		
		for( i = 0; i < gra->count; i++ )
		{
			ret += LinkList_Length(gra->la[i]);
		}
	}
	
	return ret;
}

void LGraph_DFS(LGraph* graph, int v, printf_vertices* pFunc)
{
	TLGraph* gra = (TLGraph*)graph;
	
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

void LGraph_BFS(LGraph* graph, int v, printf_vertices* pFunc)
{
	TLGraph* gra = (TLGraph*)graph;
	
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
			}
		}
		
		printf("\n");
	}
}

void LGraph_Display(LGraph* graph, printf_vertices* pFunc) //O(n * n * n)
{
	TLGraph* gra = (TLGraph*)graph;
	
	if( (gra != NULL) && (pFunc != NULL) )
	{
		int i = 0;
		int j = 0;
		
		LGraphLinkListNode* node = NULL;
		
		for(i = 0; i < gra->count; i++)
		{	
			printf("%d:",i);
			pFunc(gra->v[i]);
			printf(" ");
		}
		
		printf("\n");
		
		for(i = 0; i < gra->count; i++)
		{
			for(j = 0; j < LinkList_Length(gra->la[i]); j++)
			{
				node = (LGraphLinkListNode*)LinkList_Get(gra->la[i], j);
				
				printf("<");
				pFunc(gra->v[i]);
				printf(",");
				pFunc(gra->v[node->v]);
				printf(",");
				printf("%d",node->w);
				printf(">");
				printf(" ");
			}
		}
		printf("\n");
	}
}

