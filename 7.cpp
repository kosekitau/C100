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
    vector<P> p;
    //p.resize(n);
    for(int i=0;i<n;i++) {
        int x, y; cin>>x>>y;
        p.push_back(make_pair(x, y));
    }
    sort(p.begin(), p.end());

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int dx=p[j].first-p[i].first;
            int dy=p[j].second-p[i].second;
            int nx1=p[i].first-dy, ny1=p[i].second+dx;
            int nx2=p[j].first-dy, ny2=p[j].second+dx;
            int idx1 = lower_bound(p.begin(), p.end(), make_pair(nx1, ny1)) - p.begin();
            int idx2 = lower_bound(p.begin(), p.end(), make_pair(nx2, ny2)) - p.begin();
            if(make_pair(nx1, ny1)==p[idx1] && make_pair(nx2, ny2)==p[idx2]) ans=max(ans, dx*dx+dy*dy);
        }
    }
    cout<<ans<<endl;
    return 0;
}