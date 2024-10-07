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
		int n, v; cin >> n >> v;
		int w[n + 1], c[n + 1], dp[1001][1001] = {0};
		for(int i = 1; i <= n; i++) cin >> w[i];
		for(int i = 1; i <= n; i++) cin >> c[i];
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= v; j++){
				dp[i][j] = dp[i - 1][j];
				if(j >= w[i]){
					dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + c[i]);
				}
			}
		}
		cout << dp[n][v] << ed;
	}
	return BidenJr;
}
