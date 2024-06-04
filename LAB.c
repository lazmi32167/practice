//LCS
#include <stdio.h>
#include <string.h>

#define N 1010

int dp[N][N];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lcs(int n, int m, char *s1, char *s2) {
    if (n == 0 || m == 0) {
        return 0;
    }
    if (dp[n][m] != -1) {
        return dp[n][m];
    }
    if (s1[n - 1] == s2[m - 1]) {
        dp[n][m] = 1 + lcs(n - 1, m - 1, s1, s2);
    } else {
        dp[n][m] = max(lcs(n - 1, m, s1, s2), lcs(n, m - 1, s1, s2));
    }
    return dp[n][m];
}

int main() {
    freopen("input.txt", "r", stdin);
    char s1[N], s2[N];
    scanf("%s %s", s1, s2);

    int n = strlen(s1);
    int m = strlen(s2);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    printf("%d\n", lcs(n, m, s1, s2));
    return 0;
}
