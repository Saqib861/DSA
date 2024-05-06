#include <stdio.h>
#include <stdbool.h>

#define MAX_N 100 // Maximum array size

bool subsetSumUtil(int arr[], int n, int sum, bool dp[][MAX_N + 1]) {
    // Base cases
    if (sum == 0) {
        return true;
    }
    if (n == 0 || sum < 0) {
        return false;
    }

    // Check if already calculated in the memoization table
    if (dp[n][sum] != -1) {
        return dp[n][sum];
    }

    // Include or exclude the current element
    dp[n][sum] = subsetSumUtil(arr, n - 1, sum, dp) || subsetSumUtil(arr, n - 1, sum - arr[n - 1], dp);
    return dp[n][sum];
}

bool subsetSum(int arr[], int n, int sum) {
    bool dp[MAX_N + 1][MAX_N + 1];
    int i,j;
    for ( i = 0; i <= n; i++) {
        for (j = 0; j <= sum; j++) {
            dp[i][j] = -1; // Initialize with -1 for unknown values
        }
    }
    return subsetSumUtil(arr, n, sum, dp);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (subsetSum(arr, n, sum)) {
        printf("Found a subset with given sum\n");
    } else {
        printf("No subset with given sum\n");
    }

    return 0;
}
