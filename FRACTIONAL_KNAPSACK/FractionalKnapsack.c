#include <stdio.h>
struct Item {
    int value;
    int weight;
};

void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void sortItems(struct Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            float r1 = (float)arr[j].value / arr[j].weight;
            float r2 = (float)arr[j + 1].value / arr[j + 1].weight;

            if (r1 < r2) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
float fractionalKnapsack(struct Item arr[], int n, int capacity) {
    sortItems(arr, n);

    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= arr[i].weight) {
            // Take full item
            capacity -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            // Take fraction
            float fraction = (float)capacity / arr[i].weight;
            totalValue += arr[i].value * fraction;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    float maxValue = fractionalKnapsack(arr, n, capacity);

    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
