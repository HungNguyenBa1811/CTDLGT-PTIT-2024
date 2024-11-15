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
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n, greater<int>());
		int mid = n / 2; // chia kanguru lam 2
		int cnt = 0; // dem so kanguru dc cho vao tui
		int i = 0, j = n / 2;
		while(i < n / 2 && j < n){
			if(a[i] >= 2 * a[j]){
				cnt++;
				i++;
				j++;
			} else j++;
		}
		cout << n - cnt << ed;
	}
	return BidenJr;
}

