// CSES Problem 
vector<ll> dp(N,-1);

ll dice(int i)
{
    if (i == 0) return 1;
    if (dp[i] != -1) return dp[i];

    dp[i] = 0;
    int range = min(i, 6);

    for (int j = 1; j <= range; ++j)
    {
        dp[i] += dice(i-j);
    }
    return dp[i];
}
