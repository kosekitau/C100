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
#define MOD 100000
#define MAX_N 10000000

int main(){
    int n;
    cin>>n;
    int s[1000010];
    for(int i=0;i<1000010;i++) s[i]=0;

    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        s[a]++; s[b+1]--;
    }    
    
    for(int i=1;i<1000010;i++) s[i]+=s[i-1];
    int ans=s[0];
    for(int i=1;i<1000010;i++) ans=max(ans, s[i]);
    cout<<ans<<endl;
    return 0;
}