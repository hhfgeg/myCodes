#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 1e5+5;

char str[maxn];
int l[maxn],r[maxn],ans[maxn];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE

    int n;
    cin>>str;
    int len = strlen(str);
    int cont = 0;
    for(int i = 0;i<len;i++){
        if(str[i] == 'R') {
            cont = 0;
        }
        else {
            l[i] = cont;
            cont++;
        }
        //cout<<l[i]<<" ";
    }
    //cout<<endl;

    cont = 0;
    for(int i = len-1;i>=0;i--){
        if(str[i] == 'L') {
            cont = 0;
        }
        else {
            r[i] = cont;
            cont++;
        }
        //cout<<r[i]<<" ";
    }
    //cout<<endl;

    int num = 1000000000;

    for(int i = 0;i<len;i++){
        if(str[i] == 'R'){
            int wz = i + r[i];
            int y = num - r[i];
            ans[wz + y%2]++;
        }
        else {
            int wz = i - l[i];
            int y = num - l[i];
            ans[wz - y%2]++;
        }
    }

    for(int i =0;i<len;i++){
        if(i<len-1) cout<<ans[i]<<" ";
        else cout<<ans[i]<<endl;
    }

    return 0;
}
