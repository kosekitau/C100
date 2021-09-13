#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

struct edge{ int to, cost; };
typedef pair<int, int> P;

int V;
vector<edge> G[110];
int d[110];
int INF = 200000000;

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s]=0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i=0;i<G[v].size();i++){
            edge e = G[v][i];
            if(d[e.to] > d[v]+e.cost){
                
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(){
    int k;
    cin>>V>>k;
    vector<int> ans;

    for(int i=0;i<k;i++){
        int q; cin>>q;
        if(q){
            int c, d, e;
            cin>>c>>d>>e;
            c--; d--;
            edge E = {d, e};
            G[c].push_back(E);
            E = {c, e};
            G[d].push_back(E);

        }
        else{
            int a, b;
            cin>>a>>b;
            a--; b--;
            dijkstra(a);
            if(d[b]==INF) ans.push_back(-1);
            else ans.push_back(d[b]);
        }
    }
    
    for(auto x: ans){
        cout<<x<<endl;
    }
    return 0;
}