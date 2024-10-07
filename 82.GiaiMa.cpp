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
		string s; cin >> s;
		int n = s.size();
		s = "0" + s;
		int dp[n + 1] = {0};
		dp[0] = 1;
		for(int i = 1; i <= n; i++){
			if(s[i] - '0') dp[i] += dp[i - 1];
			int tmp = (s[i - 1] - '0') * 10 + s[i] - '0';
			if(i - 1 && tmp >= 10 && tmp <= 26) dp[i] += dp[i - 2];
		}
		cout << dp[n] << ed;
	}
	return BidenJr;
}
