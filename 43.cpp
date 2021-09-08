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
    int n;
    cin>>n;
    char S[5][n];
    int C[4][n];
    for(int i=0;i<4;i++) for(int j=0;j<n;j++) C[i][j]=0;

    for(int i=0;i<5;i++){
        string s; cin>>s;
        for(int j=0;j<s.length();j++){
            S[i][j]=s[j];
            if(S[i][j]=='R') C[0][j]++;
            else if(S[i][j]=='B') C[1][j]++;
            else if(S[i][j]=='W') C[2][j]++;
            else C[3][j]++;
        }
    }

    int dp[n+1][4];
    for(int i=0;i<=n;i++) for(int j=0;j<4;j++) dp[i][j]=INF;
    for(int i=0;i<4;i++) dp[0][i]=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                if(j!=k && j!=3 && k!=3){
                    dp[i+1][j]=min(dp[i+1][j], dp[i][k]+(5-C[j][i]));
                }
            }
        }
    }
    int ans=INF;
    for(int j=0;j<3;j++) ans=min(ans, dp[n][j]);
    cout<<ans<<endl;
    return 0;
}