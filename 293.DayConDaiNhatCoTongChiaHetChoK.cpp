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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a[n + 5], f[n + 5][55];
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			a[i] %= k;
		}
		for(int i = 0; i < k; i++) f[1][i] = INT_MIN;
		f[1][a[1]] = 1;
		for(int i = 2; i <= n; i++){
			for(int j = 0; j < k; j++){
				f[i][j] = max(f[i - 1][j], f[i - 1][(j - a[i] + k) % k] + 1);
			}
		}
		cout << f[n][0] << ed;
	}
	return BidenJr;
}

