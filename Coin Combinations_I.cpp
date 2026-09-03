vector<ll> dp(N,-1);
vector<ll> coins(101,0);
int n = 0;

ll coin(int i){
    if(i == 0) return 1;
    if(dp[i] != -1) return dp[i];
    dp[i] = 0;

    for(int j=0;j<n;j++){
        if(i - coins[j] >= 0){
            dp[i] = (dp[i] + coin(i - coins[j])) % MOD;
        }
    }
    return dp[i];
}

void solve()
{
   int x;
   cin>>n>>x;
   for(int i=0;i<n;i++){
    cin>>coins[i];
   }
   cout<<coin(x)<<endl;
}
