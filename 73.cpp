#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <functional>
#include <set>
#include <tuple>
#include <map>

using namespace std;
using ll = long long;
using Graph = vector<vector<int> >;
using P = pair<int, int>;
#define INF 2000000003
#define MOD 1000000007
#define MAX_N 10000000

ll modll(ll a, ll n){
    ll res=1;
    while(n>0){
        if(n&1) res=res*a%MOD;
        a=a*a%MOD;
        n>>=1;
    }
    return res;
}

int main(){
    ll x, y;
    cin>>x>>y;
    
    for(ll a=0;a<=x;a++){
        ll b=x-a;
        if(b%2) continue;
        b/=2;
        if(2*a+b==y){
            ll s=1, AA=1, BB=1;
            for(ll i=1;i<=a+b;i++){
                s=s*i%MOD;
                if(i==a) AA=s;
                if(i==b) BB=s;
            }
            cout<<s*modll(AA, MOD-2)%MOD*modll(BB, MOD-2)%MOD<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}