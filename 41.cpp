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
    int d, n;
    cin>>d>>n;
    int tmp[d+1], cl[n][2], h[n];
    for(int i=1;i<=d;i++) cin>>tmp[i];
    for(int i=0;i<n;i++) cin>>cl[i][0]>>cl[i][1]>>h[i];

    int dp[d+1][n];
    for(int i=0;i<=d;i++) for(int j=0;j<n;j++) dp[i][j]=0;


    for(int i=1;i<=d;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(tmp[i+1]>=cl[j][0] && cl[j][1]>=tmp[i+1] && tmp[i]>=cl[k][0] && cl[k][1]>=tmp[i])
                    dp[i+1][j]=max(dp[i+1][j], abs(h[j]-h[k])+dp[i][k]);
            }
        }
    }

    int ans=0;
    for(int i=0;i<n;i++) {
        ans=max(ans, dp[d][i]);
    }
    cout<<ans<<endl;
    return 0;
}