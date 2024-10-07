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
		int a[n + 1], dp[n + 1] = {0};
		for(int i = 1; i <= n; i++) cin >> a[i];
		dp[1] = a[1];
		for(int i = 2; i <= n; i++){
			dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
		}
		cout << dp[n] << ed;
	}
	return BidenJr;
}
