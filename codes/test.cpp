//
// Created by 15361 on 2019/9/8.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE
    long long n;
    cin>>n;
    int ans = 0;
    while(n){
        if(n%2==1) ans++;
        n/=2;
    }
    cout<<ans<<endl;
    return 0;
}