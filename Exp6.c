#include <stdio.h>
#define MAX_SIZE 10

struct object {
    int weight;
    int profit;
    float profit_by_weight;
};

struct object objects[MAX_SIZE];
int knapsack_algo(int n, int capacity);
void bubble_sort(int n);
void swap(int a, int b);

int knapsack_algo(int n, int capacity) {
    int i;
    float max_profit = 0;
    bubble_sort(n);
    for (i = 0; i < n; i ++) {
        if (capacity-objects[i].weight >= 0) {
            max_profit += objects[i].profit;
            capacity -= objects[i].weight;
        } else {
            max_profit += capacity*objects[i].profit_by_weight;
            break;
        }
    }
    return max_profit;
}

void bubble_sort(int n) {
    int i, j;
    for (i = n-1; i > 0; i --) {
        for (j = 0; j < i; j ++) {
            if (objects[j].profit_by_weight < objects[j+1].profit_by_weight) {
                swap(j, j+1);
            }
        }
    }
}

void swap(int a, int b) {
    struct object temp = objects[a];
    objects[a] = objects[b];
    objects[b] = temp;
}

void main() {
    int n, i, capacity;
    printf("Enter number of objects: ");
    scanf("%d", &n);
    for (i = 0;  i < n; i ++) {
        printf("Enter weight for object O%d: ", i+1);
        scanf("%d", &objects[i].weight);
        printf("Enter profit for object O%d: ", i+1);
        scanf("%d", &objects[i].profit);
        objects[i].profit_by_weight = (float)objects[i].profit/objects[i].weight;
    }
    printf("Enter capacity: ");
    scanf("%d", &capacity);
    printf("Max profit: %d", knapsack_algo(n, capacity));
}