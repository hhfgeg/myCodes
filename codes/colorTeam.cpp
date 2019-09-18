#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
const int maxn = 1e6+5;

char str[maxn];
long long a[maxn];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE

    cin>>str;
    int len = strlen(str);
    str[len] = ',';
    str[++len] = '\0';
    //cout<<str<<endl;

    int n = 0;

    for(int i = 0;i<len;i++){
        if(str[i] == ','){
            n++;
            a[n] = 0;
            continue;
        }
        a[n] = a[n] * 10 + str[i] - '0';

    }
    //for(int i = 0;i<n;i++) cout<<a[i]<<" ";cout<<endl;

    map <long long, int> mp;
    map <long long, int> vis;
    for(int i = 0;i<n;i++){
        int x = a[i]+1;
        mp[x]++;
    }

    long long ans = 0;

    for(int i = 0;i<n;i++){
        int x = a[i]+1;
        if(vis[x] == 0){
            vis[x] = 1;
            long long y = mp[x];
            ans += ((y + x - 1)/x)*x;
        }
    }
    cout<<ans<<endl;

    return 0;
}
