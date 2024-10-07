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
		map<int, int> mp;
		for(int i = 0; i < n; i++){
			int a; cin >> a;
			mp[a]++;
		}
		int cmax = -1, vmax = -1;
		for(auto x : mp){
			if(x.second > vmax){
				vmax = x.second;
				cmax = x.first;
			}
		}
		if(vmax > n / 2) cout << cmax << ed;
		else cout << "NO" << ed;
	}
	return BidenJr;
}

