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

int a[10], n, f;

void Try(int i, int sum){
	if(f) return;
	if(i > n){
		if(sum == 23) f = 1;
		return;
	}
	Try(i + 1, sum + a[i]);
	Try(i + 1, sum - a[i]);
	Try(i + 1, sum * a[i]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		n = 4;
		for(int i = 0; i <= 4; i++) cin >> a[i];
		sort(a, a + n + 1);
		f = 0;
		do {
		  Try(1, a[0]);
		} while(next_permutation(a, a + n + 1) && !f);
		if(f) cout << "YES" << ed;
		else cout << "NO" << ed;
	}
	return BidenJr;
}
