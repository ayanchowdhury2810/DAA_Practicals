#include <stdio.h>
#include <limits.h>
#define MAX_SIZE 9

void prims_algo(int graph[][MAX_SIZE]);
int min_weight_vertex(int *weight, int *mst);
void print_result(int graph[][MAX_SIZE], int *parent);

void prims_algo(int graph[][MAX_SIZE]) {
    int parent[MAX_SIZE], weight[MAX_SIZE], mst[MAX_SIZE] = {0}, i, j, temp;
    weight[0] = 0;
    for (i = 1; i < MAX_SIZE; i ++) {
        weight[i] = INT_MAX;
    }
    for (i = 0; i < MAX_SIZE-1; i ++) {
        temp = min_weight_vertex(weight, mst);
        mst[temp] = 1;
        for (j = 0; j < MAX_SIZE; j ++) {
            if (graph[temp][j] && !mst[j] && graph[temp][j] < weight[j]) {
                weight[j] = graph[temp][j];
                parent[j] = temp; 
            }
        }
    }
    print_result(graph, parent);
}

int min_weight_vertex(int *weight, int *mst) {
    int i, min_weight = INT_MAX, min_index;
    for (i = 0; i < MAX_SIZE; i ++) {
        if (weight[i] < min_weight && !mst[i]) {
            min_weight = weight[i];
            min_index = i;
        }
    }
    return min_index;
}   

void print_result(int graph[][MAX_SIZE], int *parent) {
    int i, total_weight = 0;
    printf("Edge\tWeight\n");
    for (i = 1; i < MAX_SIZE; i ++) {
        printf("%d-%d\t%d\n", parent[i], i, graph[i][parent[i]]);
        total_weight += graph[i][parent[i]];
    }
    printf("Total weight: %d", total_weight);
}

void main() {
    int graph[][MAX_SIZE] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    prims_algo(graph);
}