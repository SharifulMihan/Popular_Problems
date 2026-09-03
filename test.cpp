#include <bits/stdc++.h>
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)
#define ll long long
#define endl "\n"
#define pb push_back
#define yes "YES"
#define no "NO"
const int N = 2e6+5;
const ll INF = 1e18;
const int MOD = 1e9 + 7;

//===========================S.I.MiHAN=============================

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

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}