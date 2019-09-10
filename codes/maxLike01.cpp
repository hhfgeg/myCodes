//
// Created by 15361 on 2019/9/9.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
 * 01背包
 */

const int maxn = 1e3+5;
long long dp[maxn];
long long a[maxn],b[maxn];



int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE
    int V,n;
    cin>>V;
    cin>>n;
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i = 0;i<n;i++) cin>>b[i];
    dp[0] = 0;
    for(int i = 0;i<n;i++){
        for(int j = V;j-a[i]>=0;j--){
            dp[j] = max(dp[j], dp[j-a[i]] + b[i]);
        }
    }
    long long maxx = 0;
    for(int i = 0;i<=V;i++) maxx = max(maxx, dp[i]);
    cout<<maxx<<endl;
    return 0;
}