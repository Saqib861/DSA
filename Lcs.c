#include <stdio.h>

int lcs_of_three(char *seq1, int m, char *seq2, int n, char *seq3, int o) {
  int dp[m + 1][n + 1][o + 1];
int i,j,k;
  // Base Cases
  for ( i = 0; i <= m; i++) {
    for ( j = 0; j <= n; j++) {
      for ( k = 0; k <= o; k++) {
        dp[i][j][k] = 0;
      }
    }
  }

  // Build DP Table
  for (i = 1; i <= m; i++) {
    for ( j = 1; j <= n; j++) {
      for ( k = 1; k <= o; k++) {
        if (seq1[i - 1] == seq2[j - 1] && seq1[i - 1] == seq3[k - 1]) {
          dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
        } else {
          dp[i][j][k] = fmax(fmax(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
        }
      }
    }
  }

  // Return LCS length
  return dp[m][n][o];
}

int main() {
  char seq1[] = "AGGTAB";
  int m = sizeof(seq1) / sizeof(seq1[0]) - 1;
  char seq2[] = "GXTXAYB";
  int n = sizeof(seq2) / sizeof(seq2[0]) - 1;
  char seq3[] = "AGGTXAB";
  int o = sizeof(seq3) / sizeof(seq3[0]) - 1;

  int lcs_length = lcs_of_three(seq1, m, seq2, n, seq3, o);

  printf("Length of LCS of three sequences: %d\n", lcs_length);

  return 0;
}
