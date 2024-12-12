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
		int n; cin >> n;
		int x, y, z;
		cin >> x >> y >> z;
		int dp[n + 1];
		dp[0] = 0, dp[1] = x;
		for(int i = 2; i <= n; i++){
			if(i % 2) dp[i] = min(dp[i - 1] + x, dp[(i + 1) / 2] + z + y);
			else dp[i] = min(dp[i - 1] + x, dp[i / 2] + z);
		}
		cout << dp[n] << ed;
	}
	return BidenJr;
}

