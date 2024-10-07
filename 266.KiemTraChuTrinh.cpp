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
int n, m;

bool DFS(int u, int par){
	visited[u] = true;
	for(int v : ke[u]){
		if(!visited[v]){
			if(DFS(v, u)) return true;
		} else if(v != par){
			return true;
		}
	}
	return false;
}

void input(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		input();
		bool ok = false;
		for(int i = 1; i <= n; i++){
			if(!visited[i] && DFS(i, 0)){
				ok = true;
				break;
			}
		}
		if(ok) cout << "YES" << ed;
		else cout << "NO" << ed;
		for(int i = 1; i <= n; i++) ke[i].clear();	
	}
	return BidenJr;
}

