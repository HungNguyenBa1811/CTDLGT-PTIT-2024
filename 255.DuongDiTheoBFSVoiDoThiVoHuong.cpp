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

void BFS(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int x : ke[v]){
			if(!visited[x]){
				q.push(x);
				trace[x] = v;
				visited[x] = true;
			}
		}
	}
}

void input(){
	cin >> n >> m >> s >> t;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) sort(ke[i].begin(), ke[i].end());
	memset(visited, false, sizeof(visited));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--){
		input();
		BFS(s);
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
