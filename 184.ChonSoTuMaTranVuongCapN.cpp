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

int X[15], n, k;
void ktao(){
	memset(X, 0, sizeof(X));
	for(int i = 1; i <= n; i++) X[i] = i;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; t = 1;
	while(t--){
		cin >> n >> k;
		int a[n + 1][n + 1];
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				cin >> a[i][j];
		ktao();
    int cnt = 0;
    vector<string> ans;
		do {
			int sum = 0;
			for(int i = 1; i <= n; i++) sum += a[i][X[i]];
			if(sum == k){
			  cnt++;
			  string s = "";
				for(int i = 1; i <= n; i++) s += to_string(X[i]) + " ";
				ans.push_back(s);
			}
		} while(next_permutation(X + 1, X + n + 1));
		cout << ans.size() << ed;
		for(string x : ans) cout << x << ed;
	}
	return BidenJr;
}
