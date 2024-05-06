#include <stdio.h>

int min(int a, int b) {
  return (a < b) ? a : b;
}

int edit_distance(char str1[], char str2[], int m, int n) {
  // Create a DP table to store results of subproblems
  int dp[m + 1][n + 1];
int i,j;
  // Base cases: If first string is empty, only option is to insert all characters of second string
  for (i = 0; i <= m; i++) {
    dp[i][0] = i;
  }

  // Base cases: If second string is empty, only option is to delete all characters of first string
  for (j = 0; j <= n; j++) {
    dp[0][j] = j;
  }

  // Fill the DP table
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        // If last characters are same, ignore them
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        // If last characters are different, consider all three operations
        int insert = dp[i][j - 1] + 1; // Insert
        int delete = dp[i - 1][j] + 1; // Delete
        int substitute = dp[i - 1][j - 1] + 1; // Substitute
        dp[i][j] = min(insert, min(delete, substitute));
      }
    }
  }

  // Return the edit distance
  return dp[m][n];
}

int main() {
  char str1[] = "sunday";
  char str2[] = "saturday";

  int m = strlen(str1);
  int n = strlen(str2);

  printf("The edit distance between '%s' and '%s' is %d\n", str1, str2, edit_distance(str1, str2, m, n));

  return 0;
}
