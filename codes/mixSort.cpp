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
æÿ’Û≈≈–Ú
*/

struct Mx{
    int w;
    int h;
}m[105];

int cmp(Mx a, Mx b){
    if(a.w*a.h < b.w*b.h){
        return 1;
    }
    else if(a.w*a.h == b.w*b.h){
        int w1 = a.w;
        int h1 = a.h;
        int w2 = b.w;
        int h2 = b.h;
        if(w1 > h1) swap(w1,h1);
        if(w2 > h2) swap(w2,h2);
        if(w1*h2 > w2*h1) return 1;
        else if(w1*h2 == w2*h1){
            if(a.w < b.w) return 1;
        }
    }
    return 0;
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>m[i].w>>m[i].h;
    }
    sort(m,m+n,cmp);
    for(int i = 0;i<n;i++){
        if(i<n-1) cout<<m[i].w<<" "<<m[i].h<<" ";
        else cout<<m[i].w<<" "<<m[i].h<<endl;
    }
    return 0;
}
