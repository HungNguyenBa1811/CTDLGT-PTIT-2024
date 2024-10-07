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
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			pq.push(x);
		}
		ll sum, ans = 0;
		while(pq.size()){
			ll x = pq.top(); pq.pop();
			ll y = pq.top(); pq.pop();
			sum = (x + y) % MOD;
			ans = (ans + sum) % MOD;
			if(pq.size() == 0) break;
			pq.push(sum);
		}
		cout << ans << ed;
	}
	return BidenJr;
}

