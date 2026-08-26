#include <bits/stdc++.h>
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)
#define ll long long
#define endl "\n"
#define pb push_back
#define yes "YES"
#define no "NO"
const int N = 1e6 + 5;
const ll INF = 1e18;
const int MOD = 1e9 + 7;

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

void solve()
{
    int n;
    cin >> n;

    cout<<dice(n)<<endl;
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