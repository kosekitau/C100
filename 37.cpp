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
    int c[m];
    for(int i=0;i<m;i++) cin>>c[i];

    int dp[m+1][n+1];
    for(int i=0;i<=m;i++) for(int j=0;j<=n;j++) dp[i][j]=INF;    
    dp[0][0]=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<=n;j++){
            if(j>=c[i]){
                dp[i+1][j]=min(dp[i][j], dp[i+1][j-c[i]]+1);
            }
            else{
                dp[i+1][j]=dp[i][j];
            }
        }
    }

    cout<<dp[m][n]<<endl;
    return 0;
}