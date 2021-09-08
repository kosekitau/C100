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
    int n, m;
    cin>>n>>m;

    int C[m+1], D[n];
    for(int i=0;i<n;i++) cin>>D[i];
    for(int i=0;i<m;i++) cin>>C[i];

    int dp[m+1][n+1];
    for(int i=0;i<=m;i++) for(int j=0;j<=n;j++) dp[i][j]=INF;
    for(int i=0;i<=m;i++) dp[i][0]=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dp[i+1][j+1]=min(dp[i][j+1], dp[i][j]+C[i]*D[j]);
        }
    }

    int ans=INF;
    for(int i=0;i<=m;i++) ans=min(ans, dp[i][n]);
    cout<<ans<<endl;
    
    return 0;
}