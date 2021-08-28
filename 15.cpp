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
    int n;
    cin>>n;
    vector <P> p;
    for(int i=0;i<n;i++){
        int x, y;
        cin>>x>>y;
        p.push_back(make_pair(x, y));
    }
    int a[n];
    for(int i=0;i<n;i++) a[i]=i; 

    double ans=0; 
    int cnt=0;
    do{
        double s=0;
        for(int i=1;i<n;i++){
            double dx=p[a[i]].first - p[a[i-1]].first;
            double dy=p[a[i]].second - p[a[i-1]].second;
            double dm=sqrt(dx*dx+dy*dy);
            s+=dm;
        }
        ans+=s;
        cnt++;
    }while(next_permutation(a, a+n));
    printf("%.10lf\n", ans/cnt);
    
    return 0;
}