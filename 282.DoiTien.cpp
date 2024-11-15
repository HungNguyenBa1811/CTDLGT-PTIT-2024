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

int n, k, a[35];
int ans;

void Try(int i, int sum, int cnt){
	if(sum == k){
		ans = fmin(ans, cnt);
		return;
	}
	if(i > n || sum > k){
		return;
	}
	Try(i + 1, sum, cnt);
	Try(i + 1, sum + a[i], cnt + 1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	a[0] = 0;
	ans = 1e9;
	Try(1, 0, 0);
	if(ans == 1e9) cout << -1;
	else cout << ans;
	return BidenJr;
}
