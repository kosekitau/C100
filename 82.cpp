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
#define MAX_N 90010

int main(){

    while(1){
        int n; cin>>n;
        if(n==0) break;
        int table[MAX_N];
        for(int i=0;i<MAX_N;i++) table[i]=0;
        for(int i=0;i<n;i++){
            int h, m, s, start, end;
            scanf("%d:%d:%d", &h,&m,&s);
            start=h*3600+m*60+s;
            scanf("%d:%d:%d", &h,&m,&s);
            end=h*3600+m*60+s;
            table[start]++;
            table[end]--;
        }
        for(int i=1;i<MAX_N;i++) table[i]+=table[i-1];
        int ans=0;
        for(int i=0;i<MAX_N;i++) ans=max(ans, table[i]);
        cout<<ans<<endl;
    }
    return 0;
}