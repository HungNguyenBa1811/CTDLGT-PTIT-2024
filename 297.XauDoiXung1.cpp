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
		int dp[105][105] = {0};
		for(int i = 0; i < n; i++)
			dp[i][i] = 1;
		for(int i = n - 1; i >= 0; i--){
			for(int j = i + 1; j < n; j++){
				if(s[i] == s[j]) dp[i][j] += dp[i + 1][j - 1] + 2;
				else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
		cout << n - dp[0][n - 1] << ed;
	}
	return BidenJr;
}

