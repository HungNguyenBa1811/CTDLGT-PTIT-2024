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

int n, k, ok, X[1001];
vector<string> ans;

void ktao(){
	ok = 1;
	for(int i = 1; i <= n; i++) X[i] = 0;
}

void sinh(){
	int i = n;
	while(i >= 1 && X[i]){
		X[i] = 0;
		--i;
	}
	if(i == 0) ok = 0;
	else X[i] = 1;
}

int check(){
	int dp[n + 1] = {0};
	for(int i = 1; i <= n; i++){
		if(!X[i]) dp[i] = dp[i - 1] + 1;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(dp[i] >= k) cnt++;
	}
	return cnt == 1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	ktao();
	while(ok){
		if(check()){
			string s = "";
			for(int i = 1; i <= n; i++) s += (char) ((X[i]) ? 'B' : 'A');
			ans.push_back(s);
		}
		sinh();
	}
	cout << ans.size() << ed;
	for(string x : ans) cout << x << ed;
	return BidenJr;
}

