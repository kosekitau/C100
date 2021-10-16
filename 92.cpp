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
    
    while(1){
        int h;
        cin>>h;
        if(h==0) break;
        int pz[h][5], ans=0;
        for(int i=0;i<h;i++) for(int j=0;j<5;j++) cin>>pz[i][j];
        
        while(1){
            bool f=true;
            for(int i=0;i<h;i++){
                int idx=10, cnt=0;
                for(int j=0;j<3;j++){
                    if(pz[i][j]==pz[i][j+1] && pz[i][j+1]==pz[i][j+2] && pz[i][j]!=0) {
                        idx=min(idx, j);
                        cnt++;
                        f=false;
                    } 
                }
                if(idx==10) continue;
                for(int j=idx;j<idx+cnt+2;j++) {
                    ans+=pz[i][j];
                    pz[i][j]=0;
                }
            }

            if(f) break;
            for(int j=0;j<5;j++){
                for(int i=0;i<h;i++){
                    if(pz[i][j]==0){
                        for(int k=0;i-k>0;k++) swap(pz[i-k][j], pz[i-k-1][j]);                        
                    }
                }
            }
            
        }
        cout<<ans<<endl;
    }
    
    return 0;
}