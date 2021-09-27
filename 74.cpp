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
    ll n, k;
    cin>>n>>k;
    ll l=n+k-1, r=n-1;

    ll a=1, b=1, c=1;
    for(ll i=1;i<=l;i++){
        a=a*i%MOD;
        if(i==r) b=a;
        if(i==l-r) c=a;
    }
    
    cout<<a*modll(b, MOD-2)%MOD*modll(c, MOD-2)%MOD<<endl;
    
    return 0;
}