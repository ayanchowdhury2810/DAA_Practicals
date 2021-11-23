#include <stdio.h>
#define MAX_SIZE 10

struct object {
    int weight;
    int profit;
};

struct object objects[MAX_SIZE];

int knapsack_algo(int n, int capacity);
int max(int a, int b);

int knapsack_algo(int n, int capacity) {
    int matrix[n+1][capacity+1], i, j;
    for (i = 0;  i < n+1; i ++) {
        for (j = 0; j < capacity+1; j ++) {
            if (i == 0 || j == 0) {
                matrix[i][j] = 0;
            } else if (objects[i-1].weight <= j) {
                matrix[i][j] = max(objects[i-1].profit + matrix[i-1][j-objects[i-1].weight], matrix[i-1][j]); 
            } else {
                matrix[i][j] = matrix[i-1][j];
            }
        }
    }
    return matrix[i-1][j-1];
}

int max(int a, int b) {
    return a > b? a : b;
}

void main() {
    int i, n, capacity;
    printf("Enter number of objects: ");
    scanf("%d", &n);
    for (i = 0; i < n; i ++) {
        printf("Enter weight of object O%d: ", i+1);
        scanf("%d", &objects[i].weight);
        printf("Enter profit of object O%d: ", i+1);
        scanf("%d", &objects[i].profit);
    }
    printf("Enter capacity: ");
    scanf("%d", &capacity);
    printf("Max profit: %d", knapsack_algo(n, capacity));
}