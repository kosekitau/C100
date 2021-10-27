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
    double a, b, x;
    cin>>a>>b>>x;

    double ans;
    if(x > a*a*b/2){
        double d=2*b/a - 2*x/(a*a*a); 
        ans=atan(d);
        ans=ans/M_PI*180;
    }
    else{
        double d=a*b*b/(2*x);
        ans=atan(d);
        ans=ans/M_PI*180;
    }
    cout<<ans<<endl;
    return 0;
}