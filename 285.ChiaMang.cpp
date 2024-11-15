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

int n, k, a[101], ps[101], res, ans;

void Try(int sum, int cnt){
	if(ans) return;
	if(cnt == k){
		ans = 1;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(sum == res) Try(0, cnt + 1);
		else if(sum < res) Try(sum + a[i], cnt);
		else return;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		ans = res = ps[0] = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			ps[i] = ps[i - 1] + a[i];
		}
		if(ps[n] % k != 0) cout << 0 << ed;
		else {
			res = ps[n] / k;
			Try(0, 0);
			cout << ans << ed;
		}		
	}
	return BidenJr;
}
