#include<stdio.h>
int max(int a, int b) {
    if(a>b)return a;
    else return b;
}
int knapsack(int n, int capacity, int weights[], int profit[]) {
    int dp[n+1][capacity+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weights[i-1] <= j) {
                dp[i][j] = max(profit[i-1] + dp[i-1][j-weights[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
     return dp[n][capacity];
}
void main()
{
    int weights[5] = {1,2,3,4,5};
    int profits[5] = {10,15,5,20,7};
    int capacity = 10;
    int maxProfit = knapsack(5,capacity,weights,profits);
    printf("The Max profit of knapsack is %d",maxProfit);
}
