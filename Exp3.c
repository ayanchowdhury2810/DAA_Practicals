/*
    depth_first_search(graph[][MAX_SIZE], target):
        visited[MAX_SIZE] = {0}
        stack.push(target)
        while (!stack.empty()):
            temp = stack.pop()
            if (!visited[temp]):
                print(temp)
                visited[temp] = 1
                for i = 0 to MAX_SIZE-1:
                    if (graph[temp][i] && !visited[i]):
                    stack.push(j) 
*/

#include <stdio.h>
#define MAX_SIZE 10

int stack[1000], top = -1;

void depth_first_search(int graph[][MAX_SIZE], int target);
void push(int x);
int pop();

void depth_first_search(int graph[][MAX_SIZE], int target) {
    int visited[MAX_SIZE] = {0}, i, j, temp;
    push(target);
    while (top != -1) {
        temp = pop();
        if (!visited[temp]) {
            printf("%d ", temp);
            visited[temp] = 1;
            for (j = 0; j < MAX_SIZE; j ++) {
            if (graph[temp][j] && !visited[j]) {
                push(j);
            }
            }
        }
    }
}

void push(int x) {
    top ++;
    stack[top] = x;   
}

int pop() {
    int temp = stack[top];
    top --;
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
    depth_first_search(graph, 0);
}