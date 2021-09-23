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
using namespace std;
using ll = long long;
using Graph = vector<vector<int> >;
using P = pair<int, int>;
#define INF 2000000003
#define MOD 1000000007
#define MAX_N 10000000

ll modll(ll a, ll n, ll mod){
    ll res=1;
    while(n>0){
        if(n&1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int main(){
    ll w, h;
    cin>>w>>h;
    ll a=1,b=1,c=1;
    for(ll i=1;i<=w+h-2;i++){
        a=a*i%MOD;
        if(i==w-1) b=a;
        if(i==h-1) c=a;
    }
    cout<< a*modll(b, MOD-2, MOD)%MOD*modll(c, MOD-2, MOD)%MOD <<endl;
    return 0;
}