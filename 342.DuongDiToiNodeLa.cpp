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
int n, pre[1001];
bool visited[1001];
vector<int> leaf;

void input(){
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	for(int i = 2; i <= n; i++){
		if(ke[i].size() == 1)
			leaf.push_back(i);
	}
	memset(visited, false, sizeof(visited));
}

void DFS(int u){
	visited[u] = true;
	for(int v : ke[u]){
		if(!visited[v]){
			pre[v] = u;
			DFS(v);
		}
	}
}

void path(int u, int v){
	vector<int> path;
	while(v != u){
		path.push_back(v);
		v = pre[v];
	}
	path.push_back(1);
	reverse(begin(path), end(path));
	for(int x : path) cout << x << " ";
	cout << ed;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		input();
		DFS(1);
		for(int x : leaf) path(1, x);
		for(int i = 1; i <= n; i++) ke[i].clear();
		leaf.clear();
	}
	return BidenJr;
}
