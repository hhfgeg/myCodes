#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <queue>
#include <set>
using namespace std;

const int maxn  = 1e2+5;

int mp[maxn][maxn];

/*
最大子矩阵和
*/

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE

    int n;

    cin>>n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin>>mp[i][j];
            mp[i][j] = mp[i][j] + mp[i][j-1];
        }
    }

    int ans = -1000000000;

    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            int sum = 0;
            for(int k = 1;k<=n;k++){
                sum += mp[k][j] - mp[k][i-1];
                ans = max(ans, sum);
                if(sum<0) sum = 0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
