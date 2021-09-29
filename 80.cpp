#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <functional>
#include <set>
#include <tuple>
#include <map>

using namespace std;
using ll = long long;
using Graph = vector<vector<int> >;
using P = pair<int, int>;
#define INF 2000000003
#define MOD 100000
#define MAX_N 10000000

int main(){
    ll H, W, K, V;
    cin>>H>>W>>K>>V;
    ll A[H+1][W+1], a[H+1][W+1];
    for(int i=0;i<=H;i++) {
        A[i][0]=0;
        a[i][0]=0;
    }
    for(int i=0;i<=W;i++){ 
        A[0][i]=0;
        a[0][i]=0;
    }
    for(int i=1;i<=H;i++) for(int j=1;j<=W;j++) cin>>a[i][j];
    
    for(int i=1;i<=H;i++) for(int j=1;j<=W;j++) A[i][j]=a[i][j]+A[i][j-1]+A[i-1][j]-A[i-1][j-1];
        

    ll ans=0;
    for(ll k=0;k<H;k++){
        for(ll l=0;l<W;l++){
            for(ll i=1;i+k<=H;i++){
                for(ll j=1;j+l<=W;j++){
                    ll v=A[i+k][j+l]-A[i-1][j+l]-A[i+k][j-1]+A[i-1][j-1] + K*(k+1)*(l+1);
                    if(v<=V) ans=max(ans, (k+1)*(l+1));
                }
            }
        }
    }

    cout<<ans<<endl;
    
    return 0;
}