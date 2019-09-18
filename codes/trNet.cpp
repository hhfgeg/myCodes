#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

/*
À×»ð
Èý½ÇÍø¸ñ
*/
const int maxn = 1005;

int n,m;
int mp[maxn][3],mm[maxn];
vector <int >vc[maxn];
int vis[maxn];

int check(int x,int y){
    int cont = 0;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(mp[x][i] == mp[y][j])cont++;
        }
    }
    return cont == 2;
}

void getMin(int u){
    while(mp[u][0] != mm[u]){

        int tmp = mp[u][0];

        mp[u][0] = mp[u][1];
        mp[u][1] = mp[u][2];
        mp[u][2] = tmp;
    }
}

void deal(int u, int v){
    int tm[3],t=0;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(mp[u][i] == mp[v][j])tm[t++] = i;
        }
    }

    int df;
    for(int i = 0;i<3;i++){
        if(mp[v][i] != mp[u][tm[0]] && mp[v][i] != mp[u][tm[1]]) df = mp[v][i];
    }

    if(tm[0]==0 && tm[1] == 2){
        mp[v][0] = mp[u][tm[0]];
        mp[v][1] = mp[u][tm[1]];
        mp[v][2] = df;
    }
    else {
        mp[v][0] = mp[u][tm[1]];
        mp[v][1] = mp[u][tm[0]];
        mp[v][2] = df;
    }

}

void dfs(int u){

    vis[u] = 1;
    int len = vc[u].size();
    for(int i = 0;i<len;i++){
        int v = vc[u][i];
        if(vis[v] == 0){
            deal(u,v);
            getMin(v);
        }
    }
    for(int i = 0;i<len;i++){
        int v = vc[u][i];
        if(vis[v] == 0){
            dfs(v);
        }
    }

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        mm[i] = maxn;
        for(int j = 0;j<3;j++){
            cin>>mp[i][j];
            mm[i] = min(mm[i],mp[i][j]);
        }
        for(int j=0;j<i;j++){
            if(check(i,j)){
                vc[i].push_back(j);
                vc[j].push_back(i);
            }
        }
    }


    getMin(0);
    dfs(0);
    for(int i = 0;i<m;i++){
        for(int j = 0;j<3;j++) {
            if(j<2) cout<<mp[i][j]<<" ";
            else cout<<mp[i][j]<<endl;
        }
    }

    return 0;
}
