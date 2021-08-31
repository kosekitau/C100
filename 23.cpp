#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
using ll = long long;
using Graph = vector<vector<int> >;
using P = pair<int, int>;
#define INF 2000000003
#define MOD 1000000007

int main(){
    ll n, m;
    cin>>n>>m;
    n++;
    ll A[n];
    A[0]=0;
    for(int i=1;i<n;i++) cin>>A[i];

    ll dlst[n*n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) dlst[i*n+j]=A[i]+A[j];
    sort(dlst, dlst+n*n);

    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ll s=m-(A[i]+A[j]);
            int idx=lower_bound(dlst, dlst+n*n, s)-dlst;
            if(idx!=0 && m>=dlst[idx-1]+A[i]+A[j]) ans=max(ans, dlst[idx-1]+A[i]+A[j]);
        }
    }
    
    cout<<ans<<endl;

    return 0;
}