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
    Graph g;
    g.resize(n);
    for(int i=0;i<n;i++){
        int u, k; cin>>u>>k;
        u--;
        for(int j=0;j<k;j++){
            int v; cin>>v;
            v--;
            g[u].push_back(v);
        }
    }

    int depth[n];
    for(int i=0;i<n;i++) depth[i]=INF;
    queue <int> q;
    q.push(0); depth[0]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int nx: g[x]){
            if(depth[nx]>depth[x]+1){
                depth[nx]=depth[x]+1;
                q.push(nx);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(depth[i]==INF) cout<<i+1<<' '<<-1<<endl;
        else cout<<i+1<<' '<<depth[i]<<endl;
    }
    return 0;
}
