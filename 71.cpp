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
    int n, q;
    cin>>n>>q;
    ll a[n], c[q+1], s[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<q;i++) cin>>c[i];
    c[q]=1;

    s[0]=0;
    for(int i=1;i<n;i++) s[i]=(modll(a[i-1], a[i])+s[i-1])%MOD;
    
    ll ans=0, pre=1;
    for(int i=0;i<q+1;i++) {
        ll r = (s[max(c[i], pre)-1] - s[min(c[i], pre)-1])%MOD;
        if(r<0) r+=MOD;
        ans=(r+ans)%MOD;
        pre=c[i];
    }
    cout<<ans<<endl;
    return 0;
}