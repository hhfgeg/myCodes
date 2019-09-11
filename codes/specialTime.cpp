#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

/*
 *
 */


const int maxn = 1e6+5;
char h[maxn],m[maxn],str[maxn];

int Num(char c){
    if(c>='0' && c<='9') return (int)(c - '0');
    else return (int)(c - 'A' + 10);
}

int main(){
    int ans[40];
    scanf("%s",str);
    int len = strlen(str);
    int lenh = 0;
    int lenm = 0, cs = 0;
    for(int i=0;i<len;i++){
        if(str[i] == ':') {cs = 1;continue;}
        if(cs==0) {h[lenh++] = str[i];}
        else m[lenm++] = str[i];
    }
    int wc = 0;
    int t = 0;
    for(int i = 0;i<36;i++){
        int hh = 0, mm = 0;
        int flag = 1;
        int x = 1;
        for(int j = lenh-1;j>=0;j--){
            int y = Num(h[j]);
            if(j < lenh-1 && y > 0) wc = 1;
            hh = hh + y*x;
            x*=i;
            if(hh>=24 || y >= i) {flag = 0;break;}
        }
        x=1;
        for(int j = lenm-1;j>=0;j--){
            if(flag == 0) break;
            int y = Num(m[j]);
            if(j < lenm-1 && y > 0) wc = 1;
            mm = mm+ y*x;
            x*=i;
            if(mm>=60 || y >= i) {flag = 0;break;}
        }
        if(flag) ans[t++] = i;
    }

    if(wc == 0) {
        cout<<0<<endl;
        return 0;
    }

    if(t>0){
        for(int i = 0;i<t-1;i++) cout<<ans[i]<<" ";
        cout<<ans[t-1]<<endl;
    }
    else {
        cout<<"-1"<<endl;
    }
    return 0;
}