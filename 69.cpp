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

using namespace std;
using ll = long long;
using Graph = vector<vector<int> >;
using P = pair<int, int>;
#define INF 2000000003
#define MOD 1000000007
#define MAX_N 10000000

int main(){
    int q;
    cin>>q;
    int n[100010], s[100010];
    for(int i=0;i<100000;i++){
        n[i]=1;
        s[i]=0;
    }
    n[0]=0;
    n[1]=0;
    for(int i=2;i<=100000;i++){
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                n[i]=0;
                break;
            }
        }
    }

    for(int i=100000;i>=2;i--){
        if(n[i] && n[(i+1)/2]==0) n[i]=0;
    }
    
    for(int i=1;i<=100000;i++){
        s[i]=s[i-1]+n[i];
    }
    
    for(int i=0;i<q;i++){
        int l, r;
        cin>>l>>r;
        cout<<s[r]-s[l]+n[l]<<endl;
    }
    return 0;
}