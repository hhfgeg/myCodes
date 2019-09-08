//
// Created by 15361 on 2019/9/8.
//

/*
 * 2016,08,13-14双休
 */

#include <iostream>

using namespace std;

int moDay[15] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isRunYear(int x){
    if((x%400 == 0) || (x%100!=0 && x%4==0)) return 1;
    return 0;
}

int solve(int y, int m, int d){
    // 以1年1月1日为标准
    int ans = 0;
    int ys = 1;
    while(ys<y){
        ans += 365 + isRunYear(ys++);
    }

    int ms = 1;
    while(ms<m){
        ans += moDay[ms++];
        if(ms == 2 && isRunYear(ys)) ans++;
    }

    ans += d;
    return ans;
}

int main(){
    int x = solve(2016,8,14); // 求出2016，8，14距离1，1，1多少天
    int year, mouth, day;
    cin>>year>>mouth>>day;
    int y = solve(year, mouth, day); // 求出year，mouth，day距离1，1，1多少天

    if(y>=x) {
        int z = y - x; //求出差值
        if( z%7==0 || (z+1)%14 ==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    else {
        int z = x - y;
        if(z%7==0 || (z-1)%14 ==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}