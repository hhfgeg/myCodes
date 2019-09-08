//
// Created by 15361 on 2019/9/8.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <queue>
#include <set>
using namespace std;

const int maxn  = 1e6+5;

struct H{
    int ti;
    string str;
    friend bool operator < (const H &a, const H &b){
        return a.ti > b.ti;
    }
};

int vis[maxn],dp[maxn];
char st[20];
int k,n;
vector<int > vc[maxn];
int ans = 0;

void dfs(int u,int h){
    vis[u] = 1;
    int len = vc[u].size();
    if(len == 0){
        dp[u] = 0;
        return ;
    }
    ans = max(ans, h + (len-1)/k+1);
    for(int i = 0;i<len;i++){
        int v = vc[u][i];
        if(vis[v] == 0){
            dfs(v,h+1);
        }
    }

    set<int>s;
    for(int i = 0;i<len;i++){
        int v = vc[u][i];
        s.insert(-dp[v]);
    }

    int maxx = 0;
    set<int > ::iterator it = s.begin();
    int cont = k;
    for(;it!=s.end();it++){
        int x = -(*it);
        maxx = max(maxx, x + cont/k);
        cont++;
    }
    dp[u] = maxx;
}

class asd{
public:
    asd() {
        cout << "d" << endl;
    }
};

int main(){

    asd a[5], *bb[8];

    return 0;
}