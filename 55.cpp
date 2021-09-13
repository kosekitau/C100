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
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];

    int dp[n];
    fill(dp, dp+n, INF);

    int cnt=0, mx=0, m=0;
    for(int i=0;i<n;i++){
        int idx=lower_bound(dp, dp+n, A[i])-dp;
        if(mx<A[i]) {
            cnt++;
            mx=A[i];
        }
        dp[idx]=A[i];
    }
    cout<<cnt<<endl;
    return 0;
}