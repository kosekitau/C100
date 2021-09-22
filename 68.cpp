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

using namespace std;
using ll = long long;
using Graph = vector<vector<int> >;
using P = pair<int, int>;
#define INF 2000000003
#define MOD 1000000007
#define MAX_N 10000000

int main(){
    int n;
    cin>>n;
    int x=n;
    cout<<n<<':';
    for(int i=2;i*i<=n;i++){
        while(x%i==0){
            cout<<' '<<i;
            x/=i;
        }
    }
    if(x!=1) cout<<' '<<x<<endl;    
    else cout<<endl;

    return 0;
}