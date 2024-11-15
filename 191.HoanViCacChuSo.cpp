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

vector<string> a(9);
int n, k, X[9];

int solve(){
	int cmax = -1e9, cmin = 1e9;
	for(int i = 0; i < n; i++){
		int tmp = 0;
		for(int j = 0; j < k; j++){
		  tmp += (a[i][X[j]] - '0') * pow(10, k - j - 1);
		}
		cmax = fmax(cmax, tmp);
		cmin = fmin(cmin, tmp);
	}
	return cmax - cmin;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < k; i++) X[i] = i;
	int ans = 1e9;
	do {
		ans = fmin(ans, solve());
	} while(next_permutation(X, X + k));
	cout << ans << ed;
	return BidenJr;
}
