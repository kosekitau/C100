#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 10000000

struct edge{int u, v, cost;};

int par[MAX_N];
int depth[MAX_N];
edge es[MAX_N];
int V, E;

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
    sort(es, es+E, comp);
    init(V);
    int res = 0;
    for(int i=0;i<E;i++){
        edge e = es[i];
        if(!same(e.u, e.v)){
            unite(e.u, e.v);
            res+=e.cost;
        }
    }
    return res;
}

int main(){
    cin>>V>>E;
    for(int i=0;i<E;i++){
        edge e;
        cin>>e.u>>e.v>>e.cost;
        es[i]=e;
    }
    cout<<kruskal()<<endl;
    return 0;
}