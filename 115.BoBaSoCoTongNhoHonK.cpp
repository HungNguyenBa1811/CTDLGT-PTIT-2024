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
		ll n, k;
		cin >> n >> k;
		ll a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		ll cnt = 0;
		for(int i = 0; i < n - 2; i++){
			ll l = i + 1, r = n - 1;
			while(a[l] < a[r]){
				ll res = a[l] + a[i] + a[r];
				if(res < k){
					cnt += r - l;
					l++;
				} else r--;
			}
		}
		cout << cnt << ed;
	}
	return BidenJr;
}

