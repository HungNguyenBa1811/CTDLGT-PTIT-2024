#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ed "\n"
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define BidenJr 0
int x_4axis[] = {-1, 0, 0, 1};
int y_4axis[] = {0, -1, 1, 0};
int x_8axis[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y_8axis[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int MOD = 1e9 + 7;

vector<ll> v;

void sieve(){
    for(int i = 100; i > 0; i--)
        v.push_back(i * i * i);
}

string solve(string s){
    for(ll i : v){
        string tmp = to_string(i);
        int idx = 0;
        for(char j : s) if(j == tmp[idx]) idx++;
        if(idx == tmp.size()) return tmp;
    }
    return "-1";
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    sieve();
    while(t--){
        string s;
        cin >> s;
        cout << solve(s) << ed;
    }
    return BidenJr;
}
