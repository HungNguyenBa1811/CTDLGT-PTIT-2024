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
// dp[i] : dp[i - a[j]]

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n, s;
		cin >> n >> s;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		vector<bool> dp(s + 1, false);
		dp[0] = true;
		for(int i = 0; i < n; i++){
			for(int j = s; j >= a[i]; j--){
				if(dp[j - a[i]]) dp[j] = true;
			}
		}
		if(dp[s]) cout << "YES" << ed;
		else cout << "NO" << ed;		
	}
	return BidenJr;
}

