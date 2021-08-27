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
    int n; cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];

    int q; cin>>q;
    int m[q];
    for(int i=0;i<q;i++) cin>>m[i];
    
    for(int i=0;i<q;i++){
        bool f=false;
        for(int bit=0;bit<(1<<n);bit++){
            int s=0;
            for(int j=0;j<n;j++) if(bit&(1<<j)) s+=A[j];
        
            if(s==m[i]){
                f=true;
                break;
            }
        }
        if(f) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }

    return 0;
}