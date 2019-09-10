//
// Created by 15361 on 2019/9/9.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
 * 满二叉树中序遍历
 */

const int maxn = 1e6+5;
long long tree[maxn];
int n;
void print(int u, int h){
    if(h>=n) return ;
    print(u<<1, h+1);
    cout<<tree[u]<<endl;
    print(u<<1|1, h+1);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE
    cin>>n;
    for(int i = 0;i<(1<<n);i++){
        cin>>tree[i+1];
    }
    print(1,0);
    return 0;
}