#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 2e5+5;

vector<long long > vc[maxn],vv[maxn];
long long dp[maxn];

void dfs(int u, int p){
    int len = vv[u].size();
    for(int i = 0;i<len;i++){
        int v = vv[u][i];
        if(v == p) continue;
        dfs(v,u);
    }
    dp[u] = 0;
    for(int i = 0;i<len;i++){
        int v = vv[u][i];
        if(v == p) continue;
        dp[u] = max(dp[u], vc[u][i] + dp[v]);
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE

    int n;
    cin>>n;

    for(int i =0;i<n-1;i++){
        long long x,y,z;
        cin>>x>>y>>z;
        vv[x].push_back(y);
        vv[y].push_back(x);
        vc[x].push_back(z);
        vc[y].push_back(z);
    }
    dfs(1,-1);
    for(int i = 1;i<=n;i++){
        if(i<n) cout<<dp[i]<<" ";
        else cout<<dp[i]<<endl;
    }
    return 0;
}
