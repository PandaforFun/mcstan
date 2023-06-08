#include <stdio.h>
#define Total_items 100
#define Total_size 1000

int max(int a, int b) {
    if(a>b)return a;
    else return b;
}

int knapsack_input(int n, int capacity, int weights[], int values[]) {
    int dp[n+1][capacity+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weights[i-1] <= j) {
                dp[i][j] = max(values[i-1] + dp[i-1][j-weights[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    printf("The DP matrix is : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<capacity;j++)
        {
            printf("%d  ",dp[i][j]);
        }
        printf("\n");
    }
    return dp[n][capacity];
}

int main() {
    int n, capacity, weights[Total_size], values[Total_items];
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d:\n", i+1);
        printf("Weight: ");
        scanf("%d", &weights[i]);
        printf("Value: ");
        scanf("%d", &values[i]);
        printf("*********************\n");
    }
    int max_value = knapsack_input(n, capacity, weights, values);
    printf("Maximum value that can be obtained: %d\n", max_value);
    return 0;
}