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

ll binPow(ll a, ll b){
	if(b == 0) return 1;
	ll x = binPow(a, b / 2);
	if(b % 2) return (((x % MOD) * (x % MOD)) % MOD * (a % MOD)) % MOD;
	return ((x % MOD) * (x % MOD)) % MOD;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a, b;
	while(1){
		cin >> a >> b;
		if(a == b && a == 0) break;
		cout << binPow(a, b) << ed;
	}
	return BidenJr;
}

