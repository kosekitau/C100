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
    int h, w;
    cin>>h>>w;
    
    char maz[h][w];
    int bl=0;
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++){
            cin>>maz[i][j];
            if(maz[i][j]=='#') bl++;
        }
    }

    int cnt[h][w];
    fill(cnt[0], cnt[h], INF);
    cnt[0][0]=1;
    int dx[4]={1,0,-1,0}, dy[4]={0,-1,0,1};
    queue<P> que;
    que.push(make_pair(0, 0));
    while(!que.empty()){
        P p = que.front();
        que.pop();
        int x=p.first, y=p.second;
        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(maz[nx][ny]=='.' && h>nx && nx>=0 && w>ny && ny>=0) {
                maz[nx][ny]='#';
                cnt[nx][ny]=cnt[x][y]+1;
                que.push(make_pair(nx, ny));
            }    
        }
    }
    if(cnt[h-1][w-1]==INF) cout<<-1<<endl;
    else cout<<h*w-cnt[h-1][w-1]-bl<<endl;
    return 0;
}