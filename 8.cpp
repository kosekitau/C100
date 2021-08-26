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
    int n;
    cin>>n;
    ll A[n], B[n];
    for(int i=0;i<n;i++) cin>>A[i]>>B[i];

    ll ans=(1LL<<60);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ll r=0;
            for(int k=0;k<n;k++){
                r+=abs(A[i]-A[k]);
                r+=abs(A[k]-B[k]);
                r+=abs(B[k]-B[j]);
            }
            ans=min(ans, r);
        }
    }
    cout<<ans<<endl;
    return 0;
}