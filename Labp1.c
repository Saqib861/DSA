#include <stdio.h>
#include <limits.h>

int minOperations(int n) {
  // Array to store minimum operations for numbers 1 to n
  int dp[n + 1];
int i;
  // Initialize all elements with infinity (INT_MAX)
  for ( i = 0; i <= n; i++) {
    dp[i] = INT_MAX;
  }

  // Base case: 0 operations needed to reach 1
  dp[1] = 0;

  // Iterate through numbers 2 to n
  for ( i = 2; i <= n; i++) {
    // Add 1 operation to the minimum operations for the previous number
    dp[i] = dp[i - 1] + 1;

    // Check if dividing by 2 is possible and update minimum if needed
    if (i % 2 == 0) {
      dp[i] = fmin(dp[i], dp[i / 2] + 1);
    }

    // Check if dividing by 3 is possible and update minimum if needed
    if (i % 3 == 0) {
      dp[i] = fmin(dp[i], dp[i / 3] + 1);
    }
  }

  return dp[n];
}

int main() {
  int n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  int minOps = minOperations(n);
  printf("Minimum number of operations: %d\n", minOps);

  return 0;
}
