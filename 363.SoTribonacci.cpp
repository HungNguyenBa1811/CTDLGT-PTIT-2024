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
const ll MOD = 1e15 + 7;

struct mat {
	int x, y;
	ll a[5][5];
};

ll solve(ll x, ll y) {
	if (x == 0 || y == 0) return 0;
	string X = "", Y = "", Z;
	for(; x > 0; x /= 10) X = X + char(x % 10 + '0');
	for(; y > 0; y /= 10) Y = Y + char(y % 10 + '0');
	Z.resize(X.size() + Y.size(), '0');
	for(int i = 0; i < X.size(); i++){
		int c = 0;
		for(int j = 0; j < Y.size(); j++) {
			c += (Z[i + j] - '0') + (X[i] - '0') * (Y[j] - '0');
			Z[i + j] = char(c % 10 + '0');
			c /= 10;
		}
		if(c > 0) Z[i + Y.size()] += c;
	}
	ll ans = 0;
	for(int i = Z.size() - 1; i >= 0; i--) ans = (ans * 10ll + Z[i] - '0') % MOD;
	return ans;
}

mat operator * (mat a, mat b) {
	mat c = {a.x, b.y};
	for(int i = 1; i <= c.x; i++)
		for(int j = 1; j <= c.y; j++)
			c.a[i][j] = 0ll;
	for(int i = 1; i <= c.x; i++)
		for(int j = 1; j <= c.y; j++)
			for(int k = 1; k <= a.y; k++)
				c.a[i][j] = (c.a[i][j] + solve(a.a[i][k] % MOD, b.a[k][j] % MOD)) % MOD;
	return c;
}

mat Power(mat a, int x) {
	if (x == 1) return a;
	mat ans = Power(a, x/2);
	if (x%2) return ans * ans * a;
	return ans * ans;
}

int T[5], F[5];
mat a, x, ans;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 1; i <= 3; i++) T[i] = i;
	for(int i = 1; i <= 3; i++) F[i] = F[i - 1] + T[i];
	a.x = 4;
	a.y = 1;
	a.a[1][1] = (ll) F[3];
	a.a[2][1] = (ll) T[3];
	a.a[3][1] = (ll) T[2];
	a.a[4][1] = (ll) T[1];
	x.x = x.y = 4;
	x.a[1][1] = x.a[1][2] = x.a[1][3] = x.a[1][4] = 1ll;
	x.a[2][2] = x.a[2][3] = x.a[2][4] = 1ll;
	x.a[3][2] = x.a[4][3] = 1ll;
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		if (n <= 3) {
			cout << F[n] << ed;
			continue;
		}
		ans = Power(x, n - 3) * a;
		cout << ans.a[1][1] << ed;
	}
	return BidenJr;
}
