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

ll a[15][15], base[15][15];

void matrixMultiplier(ll x[15][15], int n){
	ll tmp[15][15];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			tmp[i][j] = 0;
			for(int k = 1; k <= n; k++){
				tmp[i][j] += a[i][k] * x[k][j];
				tmp[i][j] %= MOD;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] = tmp[i][j];
		}
	}
}

void binPow(ll b, int n){
	if(b == 0 || b == 1) return;
	binPow(b / 2, n);
	matrixMultiplier(a, n);
	if(b % 2) matrixMultiplier(base, n);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				cin >> a[i][j];
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				base[i][j] = a[i][j];
		binPow(k, n);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cout << a[i][j] << " ";
			}
			cout << ed;
		}
	}
	return BidenJr;
}
