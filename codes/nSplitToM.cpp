#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 205;
int dp[maxn][2][maxn],dp1[maxn][2][maxn];


/*
一个数n分成m方案数
*/

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE

    int n,m;
    scanf("%d,%d",&n,&m);
    for(int i = 1;i<=n;i++){
        dp[i][1][i] = 1;
    }

    for(int i = 1;i<=n;i++){
        for(int j =i;j<=n;j++){
            dp1[i][1][j] = 1;
        }
    }

    for(int i = 1;i<=n;i++){
        for(int j = 2;j<=m;j++){
            for(int k = 1;k<=n;k++){
                if(k<=i)dp[i][j%2][k] = dp1[i-k][(j-1)%2][k];
                dp1[i][j%2][k] = dp[i][j%2][k] + dp1[i][j%2][k-1];
            }
        }
    }

    int ans = 0;
    for(int i = 1;i<=n;i++){
        ans += dp[n][m%2][i];
    }
    cout<<ans<<endl;


    return 0;
}
