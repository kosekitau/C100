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
    int r, c;
    cin>>r>>c;
    int o[r][c], oz[r][c], ans=0;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>o[i][j];

    for(int bit=0;bit<(1<<r);bit++){
        int res=0;
        for(int i=0;i<r;i++) for(int j=0;j<c;j++) oz[i][j]=o[i][j];

        for(int i=0;i<r;i++){
            if(bit&(1<<i)){
                for(int j=0;j<c;j++) oz[i][j]=(oz[i][j]+1)%2;
            }
        }

        for(int j=0;j<c;j++){
            int cnt=0;
            for(int i=0;i<r;i++) if(oz[i][j]==1) cnt++;
            res+=max(r-cnt, cnt); 
        }
        ans=max(ans, res);
    }
    cout<<ans<<endl;
    return 0;
}