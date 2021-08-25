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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                int idx=0, lst[3]={i, j, k};
                for(int l=0;l<n;l++){
                    if(lst[idx]==s[l]-'0') idx++;
                }                
                if(idx==3) ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}