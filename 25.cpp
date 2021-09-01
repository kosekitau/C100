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

int w, h;
int c[100][100];
bool f[100][100];
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,-1,-1,-1,0,1,1,1};

void dfs(int x, int y){
    f[x][y]=false;
    for(int i=0;i<8;i++){
        int nx=x+dx[i]; int ny=y+dy[i];
        if(f[nx][ny] && c[nx][ny]==1 && nx>=0 && h>=nx && ny>=0 && w>=ny){
            dfs(nx, ny);
        }
    }
}

void solve(){
    int cnt=0;
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin>>c[i][j];
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) f[i][j]=true;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(f[i][j] && c[i][j]==1){
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}

int main(void){
    while(1){
        cin>>w>>h;
        if(w==0 && h==0) break;
        solve();
    }
    return 0;
}