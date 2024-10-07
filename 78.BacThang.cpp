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
		int n, k; cin >> n >> k;
		ll dp[n + 1] = {0};
		dp[0] = 1;
		for(int i = 1; i <= n; i++){
			// Giai quyet cac bai toan con i-1, i-2, ..., i-k, sau do cong don lai
			// Co so QHD: dp[0] = 1
			for(int j = 1; j <= min(i, k); j++){
				dp[i] = (dp[i] + dp[i - j]) % MOD;
			}
		}
		cout << dp[n] << ed;
	}
	return BidenJr;
}
