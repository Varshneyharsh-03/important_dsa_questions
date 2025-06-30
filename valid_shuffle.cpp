bool isValidShuffleOptimal(string A, string B, string C) {
    int n = A.length(), m = B.length();
    if (n + m != C.length()) return false;

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i > 0 && A[i - 1] == C[i + j - 1])
                dp[i][j] = dp[i][j] || dp[i - 1][j];
            if (j > 0 && B[j - 1] == C[i + j - 1])
                dp[i][j] = dp[i][j] || dp[i][j - 1];
        }
    }

    return dp[n][m];
}
