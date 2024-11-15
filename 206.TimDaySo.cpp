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
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int x = *min_element(a, a + n);
	int ans = 1e9;
	for(int i = 1; i <= x; i++){
		int res = 0, ok = 1;
		for(int j = 0; j < n; j++){
			int y = a[j] / (i + 1) + 1;
			if(a[j] / y != i){
				ok = 0;
				break;
			}
			res += y;
		}
		if(ok) ans = fmin(res, ans);
	}
	cout << ans << ed;
	return BidenJr;
}

