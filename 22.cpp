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

double f(double x, double p){
    return x + p/pow(2, (x/1.5));
}

int main(){
    double p;
    cin>>p;
    
    double l=0, r=1e+18;
    while(r-l>1e-8){
        double c1=(l*2.0+r)/3.0;
        double c2=(l+r*2.0)/3.0;
        if(f(c1, p) > f(c2, p)) l=c1;
        else r=c2;
    }
    printf("%.10lf\n", f(l, p));
    return 0;
}