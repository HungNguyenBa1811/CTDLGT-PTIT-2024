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

ll f[100];

char fibo(ll n, ll k){
	if(n == 1) return '0';
	if(n == 2) return '1';
	if(k <= f[n - 2]) return fibo(n - 2, k);
	return fibo(n - 1, k - f[n - 2]);
}

void sievefibo(){
	f[1] = 1;
	f[2] = 1;
	for(int i = 3; i <= 93; i++){
		f[i] = f[i - 1] + f[i - 2];
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sievefibo();
	int t; cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		cout << fibo(n, k) << ed;
	}
	return BidenJr;
}

