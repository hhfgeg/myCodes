//
// Created by 15361 on 2019/9/8.
//

//
// Created by 15361 on 2019/9/5.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <queue>
#include <set>
using namespace std;

const int maxn  = 1e6+5;

struct H{
    int ti;
    string str;
    friend bool operator < (const H &a, const H &b){
        return a.ti > b.ti;
    }
};

int vis[maxn];
char st[20];

int main(){

    int n;
    cin>>n;
    string x;
    long long y;
    map<string , long long > mp;
    map<string , int > mpt;
    set <H> s;
    int len = 0;
    int time = 0;
    while(~scanf("%s %lld",st,&y)){
        x = (string)st;
        y++;
        if(mp[x] == 0){
            if(len < n){
                len++;
                s.insert({time,x});
                mp[x] = y;
                mpt[x] = time;
            }
            else {
                set<H> :: iterator it = s.end();
                it--;
                H a = *it;
                cout<<a.str<<" "<<mp[a.str]-1<<endl;
                mp.erase(a.str);
                mpt.erase(a.str);
                s.erase(it);
                s.insert({time,x});
                mp[x] = y;
                mpt[x] = time;
            }
        }
        else {
            mp[x] = max(mp[x], y);
            set<H> :: iterator it = s.upper_bound({mpt[x],x});
            it--;
            s.erase(it);
            s.insert({time,x});
            mpt[x] = time;
        }
        time++;
    }
    return 0;
}