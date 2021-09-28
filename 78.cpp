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
    int m, n, k;
    cin>>m>>n>>k;
    char mp[m+1][n+1];
    for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) cin>>mp[i][j];
    
    int J[m+1][n+1], O[m+1][n+1], I[m+1][n+1];
    for(int i=0;i<=n;i++){
        J[0][i]=0;
        O[0][i]=0;
        I[0][i]=0;
    }
    for(int i=0;i<=m;i++){
        J[i][0]=0;
        O[i][0]=0;
        I[i][0]=0;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            J[i][j]=J[i-1][j]+J[i][j-1]-J[i-1][j-1];
            O[i][j]=O[i-1][j]+O[i][j-1]-O[i-1][j-1];
            I[i][j]=I[i-1][j]+I[i][j-1]-I[i-1][j-1];
            if(mp[i][j]=='J') J[i][j]++;
            else if(mp[i][j]=='O') O[i][j]++;
            else I[i][j]++;
        }
    }

    for(int i=0;i<k;i++){
        int rx, ry, lx, ly;
        cin>>ly>>lx>>ry>>rx;
        int ansj=J[ry][rx]-J[ly-1][rx]-J[ry][lx-1]+J[ly-1][lx-1];
        int anso=O[ry][rx]-O[ly-1][rx]-O[ry][lx-1]+O[ly-1][lx-1];
        int ansi=I[ry][rx]-I[ly-1][rx]-I[ry][lx-1]+I[ly-1][lx-1];
        cout<<ansj<<' '<<anso<<' '<<ansi<<endl;
    }

    return 0;
}