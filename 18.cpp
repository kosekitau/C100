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
    int n, q;
    cin>>n;
    vector<int> S, T;
    for(int i=0;i<n;i++){
        int s;
        cin>>s;
        S.push_back(s);
    }
    sort(S.begin(), S.end());

    cin>>q;
    int cnt=0;
    for(int i=0;i<q;i++){
        int t; cin>>t;
        int idx=lower_bound(S.begin(), S.end(), t)-S.begin();
        if(S[idx]==t) cnt++;
    }

    cout<<cnt<<endl;
    return 0;
}