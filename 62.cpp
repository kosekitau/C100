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
    int H, W;
    cin>>H>>W;
    ll dp[10][10], A[H][W];
    for(int i=0;i<10;i++) for(int j=0;j<10;j++) cin>>dp[i][j];
        
    for(int i=0;i<H;i++) for(int j=0;j<W;j++) cin>>A[i][j];

    for(int k=0;k<10;k++){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    
    ll ans=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(A[i][j]==-1) continue;
            ans+=dp[A[i][j]][1];
        }
    }
    cout<<ans<<endl;
    

    return 0;
}