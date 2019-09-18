
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int maxn  = 1e3+5;

/*
×î¼ò·ÖÊý
*/

double f[maxn];

int gcd(int a, int b){
    if(b == 0) return a;
    else gcd(b, a%b);
}

long long prim[maxn],a[maxn];
double ans[maxn];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE

    double minn = 1;
    int t = 0;
    for(long long i =2;i<100;i++){
        int flag = 1;
        for(long long j = 2;j<i;j++){
            if(i%j==0){
                flag = 0;
                break;
            }
        }
        if(flag) prim[t++]=i;
    }

    a[0] = 2;
    ans[0] = 1.0;
    double fz = 1.0;
    double fm = 2.0;
    int tt;
    for(int i = 1;i<t;i++){
        a[i] = a[i-1] * prim[i];
        ans[i] = fz/fm;
        fz *=2;
        fm =prim[i]*prim[i-1];
        if(a[i] > 1000000000LL) {
            tt = i+1;
            break;
        }
    }
    for(int i=0;i<tt;i++){
        long long sum = 0;

        for(int j = 1;j<(1<<(i+1));j++){
            int tmp = j;
            int tmt=0;
            long long ffz = 1;
            int cont = 0;
            while(tmp){
                if(tmp&1) {
                    ffz *= prim[tmt];
                    cont++;
                }
                tmt++;
                tmp>>=1;
            }
            tmp = j;
            ffz = a[i]/ffz;
            if(cont%2==0) ffz = -ffz;

            sum+=ffz;
        }
        ans[i] = (double)(a[i]-sum)/a[i];
    }

    int n;
    cin>>n;
    if(n == 1){
        cout<<"1.000000"<<endl;
        return 0;
    }
    int p = 0;
    for(int i = 0;i<tt;i++){
        if(n < a[i]){
            p = i;
            break;
        }
    }
    printf("%.6lf\n",ans[p-1]);
    return 0;
}
