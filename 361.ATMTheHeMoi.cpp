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

ll ans(int frac, ll& cnt) {
	if(frac == 1 || frac == 2 || frac == 3 || frac == 5) return 1;
	if(frac == 4 || frac == 6){
		cnt *= 2;
		return 2;
	}
	if(frac == 7 || frac == 8) return 2;
	if(frac == 9){
		cnt *= 3;
		return 3;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		ll w, c;
		cin >> w >> c;
		if (w % 1000 != 0) {
			cout << 0 << ed;
		} else {
			w /= 1000;
			ll tmp_cnt = 0, cnt = 1;
			while (w && c) {
				int frac = w % 10;
				tmp_cnt += ans(frac, cnt);
				w /= 10;
				c--;
			}
			if(w){
				tmp_cnt += w / 5;
				if (w % 5 == 4) tmp_cnt += 2;
				else if (w % 5) tmp_cnt++;
				if (w == 4 || (w % 5 == 1 && w > 1)) cnt *= 2;
				else if (w % 5 == 4 && w > 4) cnt *= 3;
			}
			cout << tmp_cnt << " " << cnt << ed;
		}
	}
	return BidenJr;
}
