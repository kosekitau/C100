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
#include <map>

using namespace std;
using ll = long long;
using Graph = vector<vector<int> >;
using P = pair<int, int>;
#define INF 2000000003
#define MOD 100000
#define MAX_N 90010

struct UnionFind{
    vector<int> par, siz;
    UnionFind(int n) : par(n, -1), siz(n, 1){ }

    int root(int x){
        if(par[x]==-1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y){
        return root(x) == root(y);
    }

    bool unite(int x, int y){
        x=root(x); y=root(y);
        if(x==y) return false;
        if(siz[x]<siz[y]) swap(x, y);
        par[y]=x;
        siz[x]+=siz[y];
        return true;
    }

    int size(int x){
        return siz[root(x)];
    }
};

int main(){
    int n, q;
    cin>>n>>q;
    UnionFind uf(n);

    vector<int> ans;
    for(int i=0;i<q;i++){
        int com, x, y;
        cin>>com>>x>>y;
        if(com) ans.push_back(uf.issame(x, y));
        else uf.unite(x, y);
    }

    for(auto x:ans) cout<<x<<endl;


    return 0;
}