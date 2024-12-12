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

int n, m, cnt, cmax;
vector<int> ke[100001];
bool visited[100001];
vector<int> tplt;

void input(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
	cmax = 0;
}

void DFS(int u){
	visited[u] = true;
	tplt.push_back(u);
	for(int v : ke[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
}

void solve(){
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			tplt.clear();
			DFS(i);
			int tmp = tplt.size();
			cmax = max(cmax, tmp);
		}
	}
	cout << cmax << ed;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
    	input();
        solve();
        for(int i = 1; i <= n; i++) ke[i].clear();
	}
	return BidenJr;
}
