#include <bits/stdc++.h>
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)
#define ll long long
#define endl "\n"
#define pb push_back
#define yes "YES"
#define no "NO"
const int N = 2e5+5;
const ll INF = 1e18;

void hanoi(int n,int s,int e){
    int helper = 6 - (s+e);
    if(n==1){
        cout<<s<<" "<<e<<endl;
    }
    else{
        hanoi(n-1,s,helper);
        cout<<s<<" "<<e<<endl;
        hanoi(n-1,helper,e);
    }
}


void solve()
{
   int n;

   cin>>n;
   hanoi(n,1,3);
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