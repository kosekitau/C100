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

bool solve(int n){
    int s=0;
    for(int i=1;i<=n;i++){
        if(n%i==0) s++;
    }
    if(s==8) return true;
    return false;
}

int main(){
    int n, s=0;
    cin>>n;
    for(int i=1;i<=n;i+=2){
        if(solve(i)) s++;
    }
    cout<<s<<endl;
    return 0;
}