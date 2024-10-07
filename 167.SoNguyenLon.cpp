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

int dp[1001][1001];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int cases; cin >> cases;
	while(cases--){
		string s;
		string t;
		cin >> s >> t;
		for(int i = 0; i <= s.size(); i++){
			for(int j = 0; j <= t.size(); j++){
				if(i == 0 || j == 0) dp[i][j] = 0;
				else{
					if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
					else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);					
				}
			}
		}
		cout << dp[s.size()][t.size()] << ed;	
	}
	return BidenJr;
}
