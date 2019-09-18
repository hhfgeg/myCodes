#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 205;
int dp[maxn][2][maxn],dp1[maxn][2][maxn];


int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE

    int n;
    cin>>n;
    if(n == 1){
        printf("%.6lf\n",1.0);
    }else if(n < 2){
        printf("%.6lf\n",1.0);
    }else if(n < 6){
        printf("%.6lf\n",1.0/2);
    }else if(n < 30){
        printf("%.6lf\n",1.0/3);
    }else if(n < 210){
        printf("%.6lf\n",4.0/15);
    }else if(n < 2310){
        printf("%.6lf\n",8.0/35);
    }
    else printf("%.6lf\n",16.0/77);

    return 0;
}
