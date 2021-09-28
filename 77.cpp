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
#define MOD 100000
#define MAX_N 10000000

int main(){
    int n, m;
    cin>>n>>m;
    ll A[n+1], S[n+1], J[m];
    for(int i=1;i<n;i++) cin>>A[i];
    for(int i=0;i<m;i++) cin>>J[i];

    S[0]=0, S[1]=0;
    for(int i=2;i<=n;i++) S[i]=S[i-1]+A[i-1];

    ll ans=0, pre=1;
    for(int i=0;i<m;i++){
        int r=max(pre+J[i], pre);
        int l=min(pre+J[i], pre);
        ans=((ans+S[r])%MOD-S[l])%MOD;
        pre+=J[i];
    }
    
    cout<<ans<<endl;

    return 0;
}