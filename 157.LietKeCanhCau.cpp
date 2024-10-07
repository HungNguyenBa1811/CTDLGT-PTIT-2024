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

vector<pair<int, int>> dscanh;
vector<int> ke[1001];
vector<int> tplt;
vector<pair<int, int>> is_cut;
bool visited[1001];
int n, m;

void DFS(int u, int s, int k){
	tplt.push_back(u);
	visited[u] = true;
	for(int v : ke[u]){
		if(!visited[v] && !(v == s && u == k) && !(v == k && u == s)){
			DFS(v, s, k);
		}
	}
}

void input(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		dscanh.push_back({fmin(x, y), fmax(x, y)});
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
				DFS(i, 0, 0);
				lt++;
				tplt.clear();
			}
		}
		for(auto x : dscanh){
			memset(visited, false, sizeof(visited));
			int cnt = 0;
			int s = x.first;
			int k = x.second;
			for(int j = 1; j <= n; j++){
				if(!visited[j]){
					DFS(j, s, k);
					cnt++;
					tplt.clear();
				}
			}
			if(lt != cnt) is_cut.push_back(x);
		}
		sort(begin(is_cut), end(is_cut), [](pair<int, int> a, pair<int, int> b)->bool{
			if(a.first == b.first) return a.second < b.second;
			return a.first < b.first;
		});
		for(auto x : is_cut) cout << x.first << " " << x.second << " ";
		cout << ed;
		is_cut.clear();
		for(int i = 1; i <= n; i++) ke[i].clear();
		dscanh.clear();
	}
	return BidenJr;
}
