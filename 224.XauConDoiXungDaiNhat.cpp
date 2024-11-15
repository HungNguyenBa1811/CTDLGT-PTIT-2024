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
		s = "-" + s;
		// fi,j = fi+1,j-1 && (si == sj)
		// fi,j: xau co doi xung khong, bat dau tai i ket thuc tai j
		bool f[n + 1][n + 1];
		memset(f, false, sizeof(f));
		for(int i = 1; i <= n; i++){
			f[i][i] = true;
			// xau do dai 1 => true
		}
		int ans = 1;
		// xet do dai 2 3 4... n
		for(int len = 2; len <= n; len++){
			for(int i = 1; i <= n - len + 1; i++){
				int j = i + len - 1;
				// fi,j do dai la len
				if(len == 2 && s[i] == s[j]) f[i][j] = true;
				else f[i][j] = f[i + 1][j - 1] && (s[i] == s[j]);
				if(f[i][j]) ans = max(ans, len);
			}
		}
		cout << ans << ed;
	}
	return BidenJr;
}

