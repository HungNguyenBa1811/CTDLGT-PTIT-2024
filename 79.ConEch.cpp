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

ll dp[101];

void sieve(){
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4; i < 51; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	sieve();
	while(t--){
		int n; cin >> n;
		cout << dp[n] << ed;
	}
	return BidenJr;
}

