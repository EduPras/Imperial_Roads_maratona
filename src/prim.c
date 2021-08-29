#include <stdio.h>
#include <stdlib.h>


int total(int *nodes, int **graph , int no_vertex)
{
    int acc = 0, i = 0;
	for (i = 1; i < no_vertex; i++)
        acc = acc + graph[i][nodes[i]];
    return acc;
}

int prim(int **graph, int no_vertex)
{
	int* nodes;
	int* values;
	char* queue;
	int node_min = 0, min = 0;
	int short_path = 0;
	int i = 0, j = 0;

	nodes = malloc(sizeof(int)*no_vertex);
	values = malloc(sizeof(int)*no_vertex);
	queue = malloc(sizeof(char)*no_vertex);
    
	for (i = 0; i < no_vertex; i++)
		values[i] = 10001, queue[i] = 0;

	values[0] = 0;
	nodes[0] = -1; 

	for (i = 0; i < no_vertex - 1; i++)
    {
		min = 10001;
		for (j = 0; j < no_vertex; j++)
		{
			if (queue[j] == 0 && values[j] < min)
			{
				min = values[j]; 
				node_min = j;
			}
		}

		queue[node_min] = 1;

		for (j = 0; j < no_vertex; j++)

			if (graph[node_min][j] && queue[j] == 0 && graph[node_min][j] < values[j])
            {
				nodes[j] = node_min;
                values[j] = graph[node_min][j];
            }
	}

	short_path =  total(nodes, graph, no_vertex);
	free (nodes);
	free (values);
	free (queue);

	return short_path;
}
