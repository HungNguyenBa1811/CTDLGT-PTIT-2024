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

int n, m;
vector<int> ke[1001];
bool check[1001];
int W[1001][1001];
bool ok;

bool BFS(int u){
	check[u] = true;
	queue<pair<int, int>> Q;
	Q.push({u , 0});
	while(!Q.empty()){
		pair<int, int> tmp = Q.front(); Q.pop();
		for(auto x : ke[tmp.first]) {
			if (!check[x]) {
				Q.push({ tmp });
				Q.push({ x, tmp.second + W[tmp.first][x] });
				check[x] = true;
				break;
			}
			else if(x == u && tmp.second + W[tmp.first][x] < 0) return true;
		}
	}
	return false;
}

bool ktra() {
	for(int i = 1; i <= n; i++) {
		memset(check, false, sizeof(check));
		if(BFS(i)) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		memset(check, false, sizeof(check));
		ok = false;
		cin >> n >> m;
		for(int i = 0; i < m; i++) {
			int u, v, w; cin >> u >> v >> w;
			ke[u].push_back(v);
			W[u][v] = w;
		}
		cout << ktra() << ed;
		for(int i = 1; i <= n; i++) ke[i].clear();
	}
}

