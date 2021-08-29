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
    int d, n, m;
    cin>>d>>n>>m;
    vector<int> D, K;
    D.push_back(0);
    for(int i=0;i<n-1;i++){
        int dn; cin>>dn;
        D.push_back(dn);
    }
    for(int i=0;i<m;i++){
        int kn; cin>>kn;
        K.push_back(kn);
    }
    sort(D.begin(), D.end());
    
    ll ans=0;
    for(int i=0;i<m;i++){
        int nxt=K[i];
        int idx=lower_bound(D.begin(), D.end(), nxt)-D.begin();
        if(idx==n) ans+=min(d-nxt, abs(D[(idx-1)%d]-nxt));
        else ans+=min(abs(D[idx%d]-nxt), abs(D[(idx-1)%d]-nxt));
    }
    cout<<ans<<endl;
    return 0;
}