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
#define INF 100010
#define MOD 1000000007

int main(){
    string s;
    cin>>s;
    int c=0, r=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='A' || s[i]=='T' || s[i]=='C' || s[i]=='G') {
            c++;
        }
        else {
            r=max(r, c);
            c=0;
        }
    }
    cout<<max(r, c)<<endl;
    return 0;
}