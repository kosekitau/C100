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
#define MOD 1000000007
#define MAX_N 10000000

int main(){
    int n;
    cin>>n;
    ll A[n+1], S[n+1];
    for(int i=1;i<=n;i++) cin>>A[i];
    S[0]=0;
    for(int i=1;i<=n;i++) S[i]=S[i-1]+A[i];

    ll r[n+1];
    for(int i=1;i<=n;i++){
        ll s=0;
        for(int j=0;j<=n-i;j++) s=max(s, S[i+j]-S[j]);
        r[i]=s;
    }
    
    for(int i=1;i<=n;i++) cout<<r[i]<<endl;
    
    return 0;
}