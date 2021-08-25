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
    p.resize(n);
    for(int i=0;i<n;i++) {
        int x, y; cin>>x>>y;
        p.push_back(make_pair(x, y));
    }
    for(P x: p){
        cout<<x.first<<' '<<x.second<<endl;
    }
    return 0;
}