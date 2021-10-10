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
    int n;
    cin>>n;
    int s[n];
    int lst[n+1];
    for(int i=0;i<n;i++) s[i]=0;
    for(int i=1;i<=n;i++) cin>>lst[i];


    int pre=lst[1], l=lst[1], idx=0;
    s[idx]++;
    for(int i=2;i<=n;i++){
        if(lst[i]==pre){
            s[idx]++;
        }
        else if(idx==0){
            if(i%2==0){
                s[idx]++;
                l=lst[i];
            }
            else{
                idx++;
                s[idx]++;
            }
        }
        else{
            if(i%2==0){
                s[idx-1]+=s[idx]+1;
                s[idx]=0;
                idx--;
            }
            else{
                idx++;
                s[idx]++;
            }
        }
        pre=lst[i];
    }
    
    int j, ans=0;
    if(l==0) j=0;
    else j=1;
    for(int i=j;i<n;i+=2) ans+=s[i];
    cout<<ans<<endl;

    return 0;
}