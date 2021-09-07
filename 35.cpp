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
    int n, w;
    cin>>n>>w;
    int V[n], W[n], dp[n+1][w+1];
    for(int i=0;i<n;i++) cin>>V[i]>>W[i];
    for(int i=0;i<=w;i++) dp[0][i]=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<=w;j++){
            if(j>=W[i]){
                dp[i+1][j]=max( dp[i][j], dp[i][j-W[i]]+V[i] );
            }
            else{
                dp[i+1][j]=dp[i][j];
            }
        }
    }
    
    cout<<dp[n][w]<<endl;
    return 0;
}