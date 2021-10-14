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
    int n;
    cin>>n;
    
    int lst[n], idx=0, cnt=0, pre=-1;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        if(a!=pre){
            cnt++;
        }
        else{
            lst[idx]=cnt;
            idx++;
            cnt=1;
        }
        pre=a;
    }
    lst[idx]=cnt;
    int ans=0;
    if(idx<3) for(int i=0;i<=idx;i++) ans+=lst[i]; 
    else for(int i=0;i<=idx-2;i++) ans=max(ans, lst[i]+lst[i+1]+lst[i+2]);
    cout<<ans<<endl;
    return 0;
}