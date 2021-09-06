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
    ll n;
    cin>>n;
    ll fib[n+1];
    fib[0]=1; fib[1]=1;

    for(int i=2;i<n+1;i++) fib[i]=fib[i-1]+fib[i-2];

    cout<<fib[n]<<endl;
    return 0;
}