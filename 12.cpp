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
    int n, m;
    cin>>n>>m;
    vector <P> p;
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        x--; y--;
        p.push_back(make_pair(x, y));
    }
    sort(p.begin(), p.end());


    int ans=1;
    if(m==0){
        cout<<ans<<endl;
        return 0;
    }
    for(int bit=0;bit<(1<<n);bit++){
        bool f=true;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(bit&(1<<i) && bit&(1<<j)){
                    int idx=lower_bound(p.begin(), p.end(), make_pair(i, j))-p.begin();
                    if(p[idx]!=make_pair(i, j)) f=false;
                }
            }
        }
        if(f) ans=max(ans, __builtin_popcount(bit));
    }
    cout<<ans<<endl;
    return 0;
}