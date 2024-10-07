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
		pair<int, int> v[n];
		for(int i = 0; i < n; i++){
			cin >> v[i].first >> v[i].second;
		}
		sort(v, v + n, [](pair<int, int> a, pair<int, int> b) {
			return a.second < b.second;
		});
		int res = 1;
		int end_time = v[0].second;
		for(int i = 1; i < n; i++){
			if(v[i].first >= end_time){
				res++;
				end_time = v[i].second;
			}
		}
		cout << res << ed;
	}
	return BidenJr;
}

