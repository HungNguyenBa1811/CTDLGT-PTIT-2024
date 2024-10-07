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
vector<int> tplt;
vector<int> is_cut;
bool visited[1001];
int n, m;

void DFS(int u){
	tplt.push_back(u);
	visited[u] = true;
	for(int v : ke[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
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
		int lt = 0;
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				DFS(i);
				lt++;
				tplt.clear();
			}
		}
		for(int i = 1; i <= n; i++){
			memset(visited, false, sizeof(visited));
			visited[i] = true;
			int cnt = 0;
			for(int j = 1; j <= n; j++){
				if(j == i) continue;
				if(!visited[j]){
					DFS(j);
					cnt++;
					tplt.clear();
				}
			}
			if(lt != cnt) is_cut.push_back(i);
		}
		for(int x : is_cut) cout << x << " ";
		cout << ed;
		is_cut.clear();
		for(int i = 1; i <= n; i++) ke[i].clear();
	}
	return BidenJr;
}
