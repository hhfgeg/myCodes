//
// Created by 15361 on 2019/9/9.
//

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


const int maxn = 1100005;
char str[maxn];
int vis[30];


int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE
    int k;
    cin>>k;
    cin>>str;

    int p1 = 0, p2 = 0;

    int maxx = 0;
    int cont = 0;
    int len = strlen(str);
    //cout<<len<<endl;
    while(p2<len){
        if(vis[str[p2] - 'a'] == 0){
            vis[str[p2] - 'a'] = 1;
            cont ++;
            if(cont > k){
                while(p1 < len){
                    vis[str[p1] - 'a'] --;
                    if(vis[str[p1] - 'a'] == 0) {
                        cont--;
                        p1++;
                        break;
                    }
                    p1++;
                }
            }
        }
        else {
            vis[str[p2] - 'a']++;
        }
        maxx = max(maxx, p2 - p1 + 1);
        p2++;
    }
    cout<<maxx<<endl;

    return 0;
}