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
    vector <int> p, q;
    for(int i=0;i<n;i++){
        int x; cin>>x; 
        x--;
        p.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x; cin>>x; 
        x--;
        q.push_back(x);
    }
    int a[n];
    for(int i=0;i<n;i++) a[i]=i; 

    int x, y, cnt=1;
    do{
        int i=0;
        for(i=0;i<n;i++) if(a[i]!=p[i]) break;
        if(i==n) x=cnt;

        for(i=0;i<n;i++) if(a[i]!=q[i]) break;
        if(i==n) y=cnt;
        cnt++;
    }while(next_permutation(a, a+n));
    cout<<abs(x-y)<<endl;
    
    return 0;
}