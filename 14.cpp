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
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    ll ans=(1LL<<60);
    for(int bit=0;bit<(1<<n);bit++){
        int pre=a[0]-1;
        if(__builtin_popcount(bit)>=k){
            ll s=0;
            for(int i=0;i<n;i++){
                if(bit&(1<<i)){
                    int dx=max(pre-a[i]+1, 0);
                    s+=dx;
                    pre=a[i]+dx;
                }
                else{
                    pre=max(pre, a[i]);
                }
            }
            ans=min(ans, s);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}