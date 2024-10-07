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
bool visited[1001];
int n, m, s, t;
int trace[1001];

void DFS(int u){
//	cout << u << ed;
	visited[u] = true;
	for(int v : ke[u]){
		if(!visited[v]){
			trace[v] = u;
			DFS(v);
		}
	}
}

void input(){
	cin >> n >> m >> s >> t;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
	}
	for(int i = 1; i <= n; i++) sort(ke[i].begin(), ke[i].end());
	memset(visited, false, sizeof(visited));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--){
		input();
		DFS(s);
		if(!visited[t]){
			cout << "-1";
		} else {
			vector<int> path;
			while(t != s){
				path.push_back(t);
				t = trace[t];
			}
			path.push_back(s);
			reverse(path.begin(), path.end());
			for(int x : path) cout << x << " ";
		}
		for(int i = 1; i <= n; i++) ke[i].clear();
		cout << ed;
	}
	return BidenJr;
}

