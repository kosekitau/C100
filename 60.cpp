#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <functional>
#include <set>
using namespace std;
using ll = long long;
using Graph = vector<vector<int> >;
using P = pair<int, int>;
#define INF 2000000003
#define MOD 1000000007

int main(){
    int V, E;
    cin>>V>>E;
    int dp[V][V];
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            if(i==j) dp[i][j]=0;
            else dp[i][j]=INF;
        }
    }

    for(int i=0;i<E;i++){
        int s, t, d;
        cin>>s>>t>>d;
        dp[s][t]=d;
    }

    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dp[i][k]==INF || dp[k][j]==INF) continue;
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    for(int i=0;i<V;i++){
        if(dp[i][i]<0) {
            cout<<"NEGATIVE CYCLE"<<endl;
            return 0;
        }
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(j!=0) cout<<' ';
            if(dp[i][j]==INF) cout<<"INF";
            else cout<<dp[i][j];
        }
        cout<<endl;
    }
    

    return 0;
}