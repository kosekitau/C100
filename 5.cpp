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
    int a, b, c, x, y;
    cin>>a>>b>>c>>x>>y;
    int mx=max(x, y)*2;
    int ans=INF;

    for(int i=0;i<=mx;i+=2){
        int s=0;
        s+=c*i;
        s+=a*max(0, (x-i/2)) + b*max(0, (y-i/2));
        ans=min(ans, s);
    }
    cout<<ans<<endl;
    return 0;
}