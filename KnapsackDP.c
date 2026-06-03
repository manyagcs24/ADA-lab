#include <stdio.h>
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (wt[i-1] <= w) {
                int include = val[i-1] + dp[i-1][w - wt[i-1]];
                int exclude = dp[i-1][w];
                dp[i][w] = (include > exclude) ? include : exclude;
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    int selected[n];
    for (int i = 0; i < n; i++)
        selected[i] = 0;
    int i = n;
    int w = W;
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i-1][w]) {
            selected[i-1] = 1;
            w = w - wt[i-1];
        }
        i--;
    }
    printf("\nItems included in Knapsack:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", selected[i]);
    }
    printf("\n");
    return dp[n][W];
}
int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int val[n], wt[n];
    printf("Enter profit of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }
    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);
    int result = knapsack(W, wt, val, n);
    printf("\nMaximum value in Knapsack = %d\n", result);
    return 0;
}
