#include <stdio.h>
#include <stdlib.h>

int merge_cities(int **origin, int **copy, int l, int a, int b)
{
    int i = 0, j = 0;
    int left = 0, right = 0;
    int origin_size = l;
    int copy_size = l - 1;
    int i_copy = 1, j_copy = 1, merge_index = 1;
    int *merged;
    a = a - 1;
    b = b - 1;
    merged = (int*)calloc(copy_size, sizeof(int));
    /*Percorrendo grafo inicial*/
    for (i = 0; i < origin_size; i++)
    {
        if(a != i && b != i)
        {
            /*Obtendo os valores do novo vértice*/
            left = origin[i][a];
            right = origin[i][b];
            
            if(right > 0 && left > 0)
            {
                if(right != 0 && right <= left)
                    merged[merge_index] = right;
                else if(left != 0 && left < right)
                    merged[merge_index] = left;
            }
            else if(right != 0) merged[merge_index] = right;
            else if(left != 0) merged[merge_index] = left;
            merge_index++;

            /*Completando o resto da matriz*/
            for(j = 0; j < origin_size; j++)
            {
                if(a != j && b != j)
                {
                    copy[i_copy][j_copy] = origin[i][j];
                    copy[j_copy][i_copy] = origin[i][j];
                    j_copy++;
                }
            }
            i_copy++;
            j_copy = 1;
       } 
    }
    j_copy = 1;

    /*Inserindo valores das arestas do novo vértice*/
    for(i = 1; i < copy_size; i++)
    {
        copy[0][i] = merged[i];
        copy[i][0] = merged[i];
    }

    free(merged);
    return origin[a][b];
}