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
int l[maxn],r[maxn];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE

    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];

    l[0] = 0;
    a[0] = -1000000000;
    a[n+1] = 1000000000;

    l[1] = 1;
    for(int i = 2;i<=n;i++){
        if(a[i]>a[i-1]){
            l[i] = l[i-1]+1;
        }
        else {
            l[i] = 1;
        }
    }

    r[n] = 1;
    for(int i = n-1;i>=1;i--){
        if(a[i]<a[i+1]){
            r[i] = r[i+1]+1;
        }
        else {
            r[i] = 1;
        }
    }

    int ans = 1;

    for(int i =1;i<=n;i++){
        if(a[i+1]-a[i-1] >=2){
            ans = max(ans, l[i-1] + r[i+1] + 1);
        }
        else {
            ans = max(ans, r[i+1] + 1);
            ans = max(ans, l[i-1] + 1);
        }
    }
    cout<<ans<<endl;

    return 0;
}
