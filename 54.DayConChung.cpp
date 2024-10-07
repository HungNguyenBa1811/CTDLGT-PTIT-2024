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
		int n, m, p, i, j, k;
		cin >> n >> m >> p;
		ll a[n], b[m], c[p];
		multiset<ll> se;
		for(int id = 0; id < n; id++) cin >> a[id];
		for(int id = 0; id < m; id++) cin >> b[id];
		for(int id = 0; id < p; id++) cin >> c[id];
		i = j = k = 0;
		while(i < n && j < m && k < p){
			if(a[i] == b[j] && a[i] == c[k]){
				se.insert(a[i]);
				i++, j++, k++;
			}
			else if(a[i] < b[j]) i++;
			else if(b[j] < c[k]) j++;
			else k++;
		}
		if(se.size() == 0) cout << "NO" << ed;
		else {
			for(ll x : se) cout << x << " ";
			cout << ed;
		}
	}
	return BidenJr;
}

