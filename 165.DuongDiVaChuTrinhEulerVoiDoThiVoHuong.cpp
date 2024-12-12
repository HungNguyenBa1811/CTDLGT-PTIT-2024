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

vector<int> ke[1001];
int n, m;

int solve(){
	int cnt_0 = 0, cnt_1 = 0;
	for(int i = 1; i <= n; i++){
		if(ke[i].empty()) return 0;
		if(ke[i].size() % 2) cnt_1++;
		else cnt_0++;
	}
	if(cnt_0 == n) return 2;
	if(cnt_1 == 2) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i < m; i++){
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		cout << solve() << ed;
		for(int i = 1; i <= n; i++) ke[i].clear();
	}
	return BidenJr;
}

