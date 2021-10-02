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
#define MAX_N 90010

int main(){
    int n, m;
    cin>>n>>m;
    int J[m];
    for(int i=0;i<m;i++) {
        cin>>J[i];
        J[i]--;
    }
    int A[n], B[n], C[n];
    for(int i=0;i<n-1;i++) cin>>A[i]>>B[i]>>C[i];
    
    ll RS[n+1], LS[n+1];
    for(int i=0;i<n+1;i++) RS[i]=LS[i]=0;
    for(int i=0;i<m-1;i++){
        if(J[i]<J[i+1]){
            RS[J[i]]++;
            RS[J[i+1]]--;
        }
        else{
            LS[J[i]]--;
            LS[J[i+1]]++;
        }
        
    }
    for(int i=1;i<n+1;i++) {
        RS[i]+=RS[i-1];
        LS[i]+=LS[i-1];
    }
    
    ll ans=0;
    for(int i=0;i<n;i++) {
        if((RS[i]+LS[i])*A[i]<(RS[i]+LS[i])*B[i]+C[i]) ans+=(RS[i]+LS[i])*A[i];
        else ans+=(RS[i]+LS[i])*B[i]+C[i];
    }
    cout<<ans<<endl;

    return 0;
}