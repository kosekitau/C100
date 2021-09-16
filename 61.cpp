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
    int N, M;
    cin>>N>>M;
    ll dp[N][N];
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(i==j) dp[i][j]=0;
            else dp[i][j]=INF;
        }
    }

    for(int i=0;i<M;i++){
        int s, t, d;
        cin>>s>>t>>d;
        s--; t--;
        dp[s][t]=d;
        dp[t][s]=d;
    }

    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    ll ans=INF;
    for(int i=0;i<N;i++){
        ll s=0;
        for(int j=0;j<N;j++){
            s=max(s, dp[i][j]);
        }
        ans=min(ans, s);
    }
    cout<<ans<<endl;
    

    return 0;
}