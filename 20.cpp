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
    ll n;
    cin>>n;
    ll A[n], B[n], C[n];
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<n;i++) cin>>B[i];
    for(int i=0;i<n;i++) cin>>C[i];
    
    sort(A, A+n); sort(B, B+n); sort(C, C+n);
    
    ll ans=0;
    for(int i=0;i<n;i++){
        ll adx=lower_bound(A, A+n, B[i])-A;
        ll cdx=lower_bound(C, C+n, B[i]+1)-C;
        ans+=adx*(n-cdx);
    }
    cout<<ans<<endl;
    return 0;
}