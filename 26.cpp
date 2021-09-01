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

int n, q, p, x;
Graph g;
int r[200010];
int sum=0;

void dfs(int cu, int pa=-1){
    for(int to: g[cu]){
        if(pa!=to){
            r[to]+=r[cu];
            dfs(to, cu);       
        }
    }
}

int main(){
    cin>>n>>q;
    g.resize(n);
    for(int i=0;i<n-1;i++){
        int a, b; cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
    }
    for(int i=0;i<n;i++) r[i]=0;

    for(int i=0;i<q;i++){
        cin>>p>>x; p--;
        r[p]+=x;
    }
    dfs(0, -1);

    for(int i=0;i<n;i++) {
        if(i) cout<<' ';
        cout<<r[i];
    }
    cout<<endl;
}
