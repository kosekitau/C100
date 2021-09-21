#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <functional>
#include <set>
#include <tuple>

using namespace std;
using ll = long long;
using Graph = vector<vector<int> >;
using P = pair<int, int>;
#define INF 2000000003
#define MOD 1000000007
#define MAX_N 10000000

struct edge{int u, v, cost;};

int par[MAX_N];
int depth[MAX_N];
edge es[MAX_N];
int V, E, K;

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        depth[i]=0;
    }
}

int find(int x){
    if(par[x]==x){
        return x;
    }
    else{
        return par[x]=find(par[x]);
    }
}

void unite(int x, int y){
    x=find(x);//それぞれの親を見つける
    y=find(y);
    if(x==y) return;
    if(depth[x]<depth[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(depth[x]==depth[y]) depth[x]++;
    }
}

bool same(int x, int y){
    return find(x)==find(y);
}

bool comp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}

int kruskal(){
    sort(es, es+E*2, comp);
    init(V);
    int res=0;
    for(int i=0;i<E*2;i++){
        edge e = es[i];
        if(!same(e.u, e.v)){
            unite(e.u, e.v);
            res+=e.cost;
        }
    }
    return res;
}

int main(){
    cin>>V;
    E=V;
    vector<tuple<int, int, int> > p;
    vector<tuple<int, int, int> > rp;
    for(int i=0;i<V;i++){
        int x, y;
        cin>>x>>y;
        p.push_back(make_tuple(x, y, i)); 
        rp.push_back(make_tuple(y, x, i)); 
    }
    sort(p.begin(), p.end());
    sort(rp.begin(), rp.end());

    for(int i=0;i<V;i++){
        edge e;
        int cost=get<0>(p[i]);
        int u=get<2>(p[i]);
        int ncost=get<0>(p[(i+1)%V]);
        int v=get<2>(p[(i+1)%V]);
        e.u=u; e.v=v; e.cost=abs(ncost-cost);
        es[i*2]=e;

        cost=get<0>(rp[i]);
        u=get<2>(rp[i]);
        ncost=get<0>(rp[(i+1)%V]);
        v=get<2>(rp[(i+1)%V]);
        e.u=u; e.v=v; e.cost=abs(ncost-cost);
        es[i*2+1]=e;
    }

    cout<<kruskal()<<endl;
    
    return 0;
}