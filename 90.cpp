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
#define MOD 998244353
#define MAX_N 3001


int main(){
    int n, m;
    cin>>n>>m;
    
    double x[n+m], y[n+m], r[n];
    for(int i=0;i<n;i++) cin>>x[i]>>y[i]>>r[i];
    for(int i=n;i<n+m;i++) cin>>x[i]>>y[i];

    double ans=INF;
    for(int i=0;i<n+m;i++){
        for(int j=0;j<n+m;j++){
            if(i==j) continue;
            double d;
            if(i<n && j<n)  d=min(r[i], r[j]);
            else if(i>=n && j<n) d=sqrt(pow(abs(x[i]-x[j]), 2) + pow(abs(y[i]-y[j]), 2)) - r[j];
            else if(i<n && j>=n) d=sqrt(pow(abs(x[i]-x[j]), 2) + pow(abs(y[i]-y[j]), 2)) - r[i];
            else d=sqrt(pow(abs(x[i]-x[j]), 2) + pow(abs(y[i]-y[j]), 2))/2;
            ans=min(ans, d);
        }
    }
    printf("%.10lf\n", ans);
    return 0;
}