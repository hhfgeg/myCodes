//
// Created by 15361 on 2019/9/8.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
 * 两段最大和
 */

const int maxn = 1e6+5;
long long a[maxn],lmax[maxn],rmax[maxn];

void split(string s, long long a[], int &x){
    x = 0;
    a[x] = 0;
    int p = 0;
    int flag = 1;
    if(s[p] == '-') flag = -1;
    for(int i = 0;i<s.size();i++){
        if(s[i] == ','){
            a[x] = flag*a[x];
            x++;
            a[x]=0;
            flag = 1;
            continue;
        }
        if(s[i]=='-'){
            flag = -1;
            continue;
        }
        a[x] = 10*a[x] + s[i] - '0';
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE
    string s = "1213,1234,1345,1456,1234,2341";
    s += ',';
    int len;

    string str;
    cin>>str;
    str+=',';
    split(str, a, len);
    if(len == 1){
        cout<<a[0]<<endl;
        return 0;
    }
    lmax[0] = a[0];
    long long sum = a[0];
    if(sum<0) sum = 0;
    for(int i = 1;i<len;i++){
        sum += a[i];
        if(sum < 0){
            sum = 0;
            lmax[i] = max(a[i], lmax[i-1]);
            continue;
        }
        lmax[i] = max(sum, lmax[i-1]);
    }

    rmax[len-1] = a[len-1];
    sum = a[len-1];
    if(sum<0) sum = 0;
    for(int i = len-2;i>=0;i--){
        sum += a[i];
        if(sum < 0){
            sum = 0;
            rmax[i] = max(a[i], rmax[i+1]);
            continue;
        }
        rmax[i] = max(sum, rmax[i+1]);
    }
    long long maxx = -1000000000;
    for(int i = 0;i<len-1;i++){
        maxx = max(maxx, lmax[i] + rmax[i+1]);
    }
    cout<<maxx<<endl;
    return 0;
}
/*
 * -1,2,5,7,-3,1,-5,2,8,9,1,-11,-12,13,2,5
 * 47
 * 5,-10,4
 * 9
 * -2
 * -2
 * 5,-2
 * 3
 * 5,-2,1,2,-1,-1,3
 * 9
 * 5,-2,3,-1,-1
 * 8
 * 5,-2,-3,-1,-1
 * 4
 * -15,2,-3
 * -1
 */