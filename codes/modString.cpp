#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1e5+5;
const long long mod = 1e9+7;

long long dp[maxn][15];
char str[maxn];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE

    cin>>(str+1);
    int len = strlen(str+1);
    dp[0][0] = 1;
    for(int i = 1;i<=len;i++){
        if(str[i] == '?'){
            for(int x = 0;x<10;x++){
                for(int j = 0;j<13;j++){
                int k = (j*10 + x)%13;
                    dp[i][k] = (dp[i][k] + dp[i-1][j])%mod;
                }
            }
        }
        else {
            int x = str[i] - '0';
            for(int j = 0;j<13;j++){
                int k = (j*10 + x)%13;
                dp[i][k] = (dp[i][k] + dp[i-1][j])%mod;
            }
        }
    }
    cout<<dp[len][5]<<endl;
    return 0;
}
