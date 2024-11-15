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

int k, n, m, ans;
vector<int> ke[100001];
bool visited[100001];
int cnt[100001];
vector<int> pos;

void input(){
	cin >> k >> n >> m;
	for(int i = 0; i < k; i++){
		int x; cin >> x;
		pos.push_back(x);
	}
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
	}
	memset(visited, false, sizeof(visited));
}

void DFS(int u){
	cnt[u]++;
	visited[u] = true;
	for(int v : ke[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	for(int x : pos){
		memset(visited, false, sizeof(visited));
		DFS(x);
	}
	ans = 0;
	for(int i = 1; i <= n; i++){
		if(cnt[i] == k) ans++;
	}
	cout << ans << ed;
	return BidenJr;
}

