#include <stdio.h>
#include <limits.h>
#define MAX_SIZE 9

void dijkstras_algo(int graph[][MAX_SIZE]);
int min_distance_vertex(int *distance, int *spt);

void dijkstras_algo(int graph[][MAX_SIZE]) {
    int distance[MAX_SIZE], spt[MAX_SIZE] = {0}, i, j, temp;
    distance[0] = 0;
    for (i = 1; i < MAX_SIZE; i ++) {
        distance[i] = INT_MAX;
    }
    for (i = 0; i < MAX_SIZE-1; i ++) {
        temp = min_distance_vertex(distance, spt);
        spt[temp] = 1;
        for (j = 0; j < MAX_SIZE; j ++) {
            if (graph[temp][j] && !spt[j] && distance[temp] + graph[temp][j] < distance[j]) {
                distance[j] = distance[temp] + graph[temp][j];
            }
        }
    }
    printf("Vertex\tDistance from source\n");
    for (i = 0; i < MAX_SIZE; i ++) {
        printf("%d\t%d\n", i, distance[i]);
    }
}

int min_distance_vertex(int *distance, int *spt) {
    int i, min_distance = INT_MAX, min_index;
    for (i = 0; i < MAX_SIZE; i ++) {
        if (distance[i] < min_distance && !spt[i]) {
            min_distance = distance[i];
            min_index = i;
        }
    }
    return min_index;
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
    dijkstras_algo(graph);
}