// CSES Problem
vector<ll> dp(N,-1);

ll digits(int i)
{
    if (i == 0) return 0;
    //if (i == 10) return 2;;
    if(dp[i] != -1) return dp[i];
    dp[i] = N;
    for (char c : to_string(abs(i))){
        int digit = c - '0';
        if(digit == 0) continue;
        dp[i] = min(dp[i],digits(i-digit) + 1);
    }
    return dp[i];
}
