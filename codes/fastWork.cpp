#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int maxn  = 1e6+5;

/*
«Æ¿œ∞Â∏œπ§
*/

struct H{
    int d,c;
}w[25];

int cmp(H a, H b){
    return a.d<b.d || (a.d == b.d && a.c<b.c);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>w[i].d>>w[i].c;
    }
    sort(w,w+n,cmp);

    int s = 0;
    int minn = 1000000000;

    for(int i=0;i<(1<<n);i++){
        int vis[25];
        int x = i;
        for(int j = 0;j<n;j++){
            vis[j] = x&1;
            x>>=1;
        }

        int s = 0;
        int ans = 0;
        for(int j = 0;j<n;j++){
            if(vis[j] == 1){
                s += w[j].c;
                if(s > w[j].d){
                    ans+= (s - w[j].d);
                }
            }
        }
        for(int j = 0;j<n;j++){
            if(vis[j] == 0){
                s += w[j].c;
                if(s > w[j].d){
                    ans+= (s - w[j].d);
                }
            }
        }
        minn = min(minn, ans);

    }

    cout<<minn<<endl;

    return 0;
}













