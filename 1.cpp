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

int solve(int n, int x){
    int s=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++) if(i+j+k==x) s++;
        }
    }
    return s;
}

int main(){
    int n, x;
    
    while(1){
        int s=0;
        cin>>n>>x;
        if(n==0 && x==0) break;
        s+=solve(n, x);
        cout<<s<<endl;
    }
    return 0;
}