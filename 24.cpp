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

int n;
vector<vector<int> > p;
int d[1010];
int f[1010];
int cnt=1;

void dfs(int x){
    for(int i: p[x]){
        if(d[i]==INF){
            d[i]=cnt;
            cnt++;
            dfs(i);
        }
    }
    f[x]=cnt;
    cnt++;
}

int main(){
    cin>>n;
    p.resize(n);
    for(int i=0;i<n;i++) {
        d[i]=INF;
        f[i]=INF;
    }
    for(int i=0;i<n;i++){
        int idx; cin>>idx; idx--;
        int k; cin>>k;
        for(int j=0;j<k;j++){
            int x; cin>>x; x--;
            p[idx].push_back(x);
        }
    }

    for(int i=0;i<n;i++){
        if(d[i]==INF) {
            d[i]=cnt;
            cnt++;
            dfs(i);
        }
    }

    for(int i=0;i<n;i++){
        cout<<i+1<<' '<<d[i]<<' '<<f[i]<<endl;
    }
    return 0;
}