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
    int h, w, n;
    cin>>h>>w>>n;
    int sx, sy, glst[n+1][2];
    char mz[h][w];
    int cnt[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>mz[i][j];
            if(mz[i][j]=='S'){
                sx=i;
                sy=j;
            }
            if(mz[i][j]!='S' && mz[i][j]!='.' && mz[i][j]!='X'){
                int idx=mz[i][j]-'0';
                glst[idx][0]=i;
                glst[idx][1]=j;
            }
        }
    }
    

    int dx[4]={1,0,-1,0}, dy[4]={0,-1,0,1};
    int ans=0;
    for(int i=1;i<=n;i++){
        fill(cnt[0], cnt[h], INF);
        cnt[sx][sy]=0;
        queue <P> que;
        que.push(make_pair(sx, sy));
        int gx, gy;
        gx=glst[i][0]; gy=glst[i][1];
        while(!que.empty()){
            P p = que.front();
            que.pop();
            int x, y;
            x=p.first; y=p.second;
            if(x==gx && y==gy) break;
        
            for(int j=0;j<4;j++){
                int nx=x+dx[j], ny=y+dy[j];
                if(mz[nx][ny]!='X' && cnt[nx][ny]==INF && nx>=0 && h>nx && ny>=0 && w>ny){
                    que.push(make_pair(nx, ny));
                    cnt[nx][ny]=cnt[x][y]+1;
                }
            }
        }
        sx=gx;
        sy=gy;
        ans+=cnt[gx][gy];
    }
    cout<<ans<<endl;

    return 0;
}
