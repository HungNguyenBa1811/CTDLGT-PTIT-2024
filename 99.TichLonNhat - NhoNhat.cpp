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
		int n, m;
		cin >> n >> m;
		int a[n], b[m];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < m; i++) cin >> b[i];
		sort(a, a + n);
		sort(b, b + m);
		cout << 1ll * a[n - 1] * b[0] << ed;
	}
	return BidenJr;
}

