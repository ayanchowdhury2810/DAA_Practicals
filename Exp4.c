#include <stdio.h>
#define MAX_SIZE 10

int queue[1000], front = -1, rear = -1;

void breadth_first_search(int graph[][MAX_SIZE], int target);
void enqueue(int x);
int dequeue();

void breadth_first_search(int graph[][MAX_SIZE], int target) {
    int visited[MAX_SIZE] = {0}, i, j, temp, k;
    enqueue(target);
    while (front != -1 && rear != -1) {
        temp = dequeue();
        if (!visited[temp]) {
            printf("%d ", temp);
            visited[temp] = 1;
            for (j = 0; j < MAX_SIZE; j ++) {
            if (graph[temp][j] && !visited[j]) {
                enqueue(j);
            }
            }
        }
    }
}

void enqueue(int x) {
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear ++;
    }
    queue[rear] = x;
} 

int dequeue() {
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    int temp = queue[front];
    front ++;
    return temp;
}

void main() {
    int graph[][MAX_SIZE] = {
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}
    };
    breadth_first_search(graph, 0);
}