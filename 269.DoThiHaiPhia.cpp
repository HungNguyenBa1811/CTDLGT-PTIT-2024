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
int parent[1001];
int color[1001];
int n, m;

void input(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	memset(color, 0, sizeof(color));
}

// 1 red
// 2 green
bool DFS(int u, int par){
	color[u] = 3 - color[par];
	for(int v : ke[u]){
		if(color[v] == 0){
			if(!DFS(v, u)) return false; // ko la do thi 2 phia
		} else if(color[u] == color[v]) return false; // 2 thg ke nhau trung mau
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		input();
		color[0] = 1;
		bool ok = true;
		for(int i = 1; i <= n; i++){
			if(!color[i] && !DFS(i, 0)){
				ok = false;
			}
		}
		if(ok) cout << "YES" << ed;
		else cout << "NO" << ed;
		for(int i = 1; i <= n; i++) ke[i].clear();	
	}
	return BidenJr;
}
