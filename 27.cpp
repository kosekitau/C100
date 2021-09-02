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

int m, n;
int ic[100][100];
int seen[100][100];
int ans=0, cnt;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

void dfs(int y, int x, int c){
    seen[y][x]=1;
    for(int i=0;i<4;i++){
        int nx=x+dx[i]; int ny=y+dy[i];
        if(seen[ny][nx]==0 && ic[ny][nx] && nx>=0 && m>nx && ny>=0 && n>ny){
            dfs(ny, nx, c+1);
        }
    }
    cnt=max(cnt, c);
    seen[y][x]=0;
}

int main(){
    cin>>m>>n;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>ic[i][j];    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ic[i][j]==0) continue;
            cnt=0;
            memset(seen, 0, sizeof(seen));
            dfs(i, j, 1);
            ans=max(ans, cnt);
        }
    }
    cout<<ans<<endl;
}
