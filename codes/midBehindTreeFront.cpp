#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <queue>
#include <set>
using namespace std;

const int maxn  = 1e6+5;

/*
中后序求前序二叉树
*/

char mid[maxn],behind[maxn],fron[maxn];
int cont;
void solve(int ml, int mr, int bl, int br){

    if(ml > mr){
        return ;
    }
    int mi;
    for(int i=ml;i<=mr;i++){
        if(mid[i] == behind[br]){
            mi = i;
            break;
        }
    }

    int len = mi - ml;
    fron[cont++] = behind[br];
    solve(ml,mi-1,bl,bl+len-1);
    solve(mi+1,mr,bl+len,br-1);
}


int main(){


    cin>>mid;
    cin>>behind;
    int len = strlen(mid);

    solve(0,len-1,0,len-1);
    cont = 0;
    fron[len] = '\0';
    cout<<fron<<endl;
    return 0;
}
