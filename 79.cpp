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
#define MAX_N 10000000

int main(){
    int N, M, Q;
    cin>>N>>M>>Q;
    int cnt[N+1][N+1];
    for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) cnt[i][j]=0;
    for(int i=0;i<M;i++){
        int L, R;
        cin>>L>>R;
        cnt[L][R]++;
    }
    for(int i=1;i<=N;i++) for(int j=2;j<=N;j++) cnt[i][j]+=cnt[i][j-1];

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<cnt[i][j]<<' ';
        }
        cout<<endl;
    }

    for(int i=0;i<Q;i++){
        int p, q;
        cin>>p>>q;
        int ans=0;
        for(int i=p;i<=q;i++) ans+=cnt[i][q];
        cout<<ans<<endl;
    }
    
    return 0;
}