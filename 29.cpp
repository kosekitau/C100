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
    int r, c, sx, sy, gx, gy;
    cin>>r>>c>>sx>>sy>>gx>>gy;
    sx--; sy--;
    gx--; gy--;
    char mz[r][c];
    int cnt[r][c];
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>mz[i][j];
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cnt[i][j]=0;

    int dx[4]={1,0,-1,0}, dy[4]={0,-1,0,1};
    queue <P> que;
    que.push(make_pair(sx, sy));
    while(!que.empty()){
        int x, y;
        P p = que.front();
        que.pop();
        x=p.first; y=p.second;
        if(x==gx && y==gy) break;
        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(mz[nx][ny]=='.' && nx>=0 && r>nx && ny>=0 && c>ny){
                que.push(make_pair(nx, ny));
                mz[nx][ny]='#';
                cnt[nx][ny]=cnt[x][y]+1;
            }
        }
    }
    cout<<cnt[gx][gy]<<endl;

    return 0;
}
