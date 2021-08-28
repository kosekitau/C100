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
    int n, m;
    cin>>n>>m;
    int k[m], s[m][10];
    for(int i=0;i<m;i++){
        cin>>k[i];
        for(int j=0;j<k[i];j++) {
            cin>>s[i][j];
            s[i][j]--;
        }
    }
    int p[m];
    for(int i=0;i<m;i++) cin>>p[i];

    int ans=0;
    for(int bit=0;bit<(1<<n);bit++){
        int a=0;
        for(int j=0;j<m;j++){
            int r=0;
            for(int z=0;z<k[j];z++){
                if(bit & (1<<s[j][z])) r++;
            }
            if(r%2==p[j]) a++;
        }
        if(a==m) ans++;
    }
    cout<<ans<<endl;
    return 0;
}