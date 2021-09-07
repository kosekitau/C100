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
    int q;
    cin>>q;
    
    for(int i=0;i<q;i++){
        string X, Y;
        cin>>X>>Y;
        int dp[X.length()+1][Y.length()+1];
        for(int i=0;i<=X.length();i++) for(int j=0;j<=Y.length();j++) dp[i][j]=0;

        for(int i=1;i<=X.length();i++){
            for(int j=1;j<=Y.length();j++){
                if(X[i-1]==Y[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        cout<<dp[X.length()][Y.length()]<<endl;
    }

    return 0;
}