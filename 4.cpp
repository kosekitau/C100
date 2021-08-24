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
#define INF 100010
#define MOD 1000000007

int main(){
    int n, m;
    cin>>n>>m;
    ll A[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>A[i][j];
    
    ll r=0;
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            ll s=0;
            for(int k=0;k<n;k++){
                s+=max(A[k][i], A[k][j]);
            }
            r=max(r, s);
        }
    }
    cout<<r<<endl;
    return 0;
}