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

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];
    
    ll dp[n][21];
    fill(dp[0], dp[n], 0);
    dp[0][A[0]]=1;

    for(int i=1;i<n;i++){
        for(int j=0;j<21;j++){
            if(dp[i-1][j]>0 && j-A[i]>=0){
                dp[i][j-A[i]]+=dp[i-1][j];
            }
            if(dp[i-1][j]>0 && 21>j+A[i]){
                dp[i][j+A[i]]+=dp[i-1][j];
            }
        }
    }
    cout<<dp[n-2][A[n-1]]<<endl;
    return 0;
}