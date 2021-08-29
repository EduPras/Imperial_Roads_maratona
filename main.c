#include<stdio.h>
#include<stdlib.h>
#include"lib/cmerge.h"
#include"lib/prim.h"

int main()
{
    int n_vertex = 0, n_roads = 0, n_queries = 0;
    int i = 0, j = 0;
    int a = 0, b = 0, cost = 0;
    int **origin;
    int ** copy;
    const char* INPUT_FILENAME = "./input/std1.in";

    FILE *input = fopen(INPUT_FILENAME, "r");
    FILE *output = fopen("./output/out.sol", "w");
    
    fscanf(input, "%d %d", &n_vertex, &n_roads);

    origin = calloc(n_vertex, sizeof(int*));
    copy = calloc(n_vertex - 1, sizeof(int*));
    
    /*Preenchendo GRAFO e NOVO_GRAFO com 0*/
    for (i = 0, j = -1; i < n_vertex; i++, j++)
    {
        if(j >= 0)
            copy[j] = (int*)calloc(n_vertex -1, sizeof(int));
        origin[i] = calloc(n_vertex, sizeof(int));
    }

    for(i = 0; i< n_roads; i++)
    {
  	    fscanf(input,"%d %d %d", &a, &b, &cost);
        origin[a-1][b-1] = cost;
        origin[b-1][a-1] = cost;
    }

    fscanf(input,"%d", &n_queries);

    for(i = 0; i < n_queries; i++)
    {
        int value = 0;
    	fscanf(input,"%d %d", &a, &b);
        value = merge_cities(origin,copy,n_vertex,a,b); 
        /*Merge Cities + Prim*/
        value = value + prim(copy, n_vertex-1);
        fprintf(output, "%d\n", value);
    }
    free(origin);
    free(copy);
    fclose(input);
    fclose(output);
    return 0;
}
