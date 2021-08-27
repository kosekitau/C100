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
    int m;
    cin>>m;
    vector<P> ori;
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        ori.push_back(make_pair(x, y));
    }
    int n;
    cin>>n;
    vector<P> lst;
    for(int i=0;i<n;i++){
        int x, y;
        cin>>x>>y;
        lst.push_back(make_pair(x, y));
    }
    sort(lst.begin(), lst.end());

    int ansx, ansy;
    for(int i=0;i<n;i++){
        int dx=lst[i].first-ori[0].first;
        int dy=lst[i].second-ori[0].second;
        bool f=true;
        for(int j=0;j<m;j++){
            P p = make_pair(ori[j].first+dx, ori[j].second+dy);
            int idx=lower_bound(lst.begin(), lst.end(), p)-lst.begin();
            if(lst[idx]!=p) f=false;
        }
        if(f){
            ansx=dx;
            ansy=dy;
        }
    }
    cout<<ansx<<' '<<ansy<<endl;
    return 0;
}