//
// Created by 15361 on 2019/9/8.
//

#include <iostream>
using namespace std;

const int maxn = 1005;
const int mod = 1000000007LL;
long long dp1[maxn][maxn],dp2[maxn][maxn],dp3[maxn][maxn];
/*
 *
 */
int ans;
int a[maxn];

int main(){
    int n;
    cin>>n;
    for(int i = 2;i<=n;i++){
        cin>>a[i];
    }
    dp1[1][1] = 1;
    dp2[1][1] = 1;
    dp3[1][1] = 1;
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<i;j++){
            if(a[i] == 0){
                dp1[i][j] = (dp1[i][j] + dp2[i-1][j-1])%mod;
            }
            else {
                dp1[i][j] = (dp1[i][j] + dp3[i-1][j])%mod;
            }
        }
        if(a[i] == 0) dp1[i][i] = (dp1[i][i] + dp2[i-1][i-1])%mod;

        for(int j = 1;j<=i;j++){
            dp2[i][j] = (dp1[i][j] + dp2[i][j-1])%mod;
        }

        for(int j = i;j>=1;j--){
            dp3[i][j] = (dp1[i][j] + dp3[i][j+1])%mod;
        }
    }
    cout<<dp2[n][n]<<endl;
    return 0;
}

/*
排列计数
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
给定一个长度为N-1且只包含0和1的序列A1到AN-1，如果一个1到N的排列P1到PN满足对于1≤i<N，当Ai=0时Pi<Pi+1，当Ai=1时Pi>Pi+1，则称该排列符合要求，那么有多少个符合要求的排列？

输入
第一行包含一个整数N，1<N≤1000。

第二行包含N-1个空格隔开的整数A1到AN-1，0≤Ai≤1

输出
输出符合要求的排列个数对109+7取模后的结果。


样例输入
4
1 1 0
样例输出
3

提示
样例解释
符合要求的排列为{3 2 1 4}、{4 2 1 3}和{4 3 1 2}。
 */