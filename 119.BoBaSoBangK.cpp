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
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		int f = 0;
		for(int i = 0; i < n - 1; i++){
			for(int j = i + 1; j < n; j++){
				int r = upper_bound(a + j + 1, a + n, k - a[i] - a[j]) - a;
				int l = lower_bound(a + j + 1, a + n, k - a[i] - a[j]) - a;
				if(r - l > 0){
					f = 1;
					break;
				}
			}
			if(f) break;
		}
		if(f) cout << "YES" << ed;
		else cout << "NO" << ed;
	}
	return BidenJr;
}
