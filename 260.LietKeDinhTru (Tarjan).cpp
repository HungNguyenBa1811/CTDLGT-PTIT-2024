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
bool is_cut[1001]; // check xem co phai dinh tru k
int n, m, timer = 0;
int disc[1001]; // thoi gian tham 1 dinh
int low[1001]; // thoi gian nho nhat cua cac to tien (cac dinh co the voi toi dc) tai i

// DK de la dinh tru:
// u la goc, >= 2 con
// low[u] >= disc[u]

void input(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	memset(disc, 0, sizeof(disc));
	memset(low, 0, sizeof(low));
	memset(is_cut, false, sizeof(is_cut));
}

void DFS(int u, int par){
	low[u] = disc[u] = ++timer;
	int child = 0;
	for(int v : ke[u]){
		if(v == par) continue;
		if(!disc[v]){
			++child;
			DFS(v, u);
			low[u] = min(low[u], low[v]);
			if(par != -1 && low[v] >= disc[u]){ // ko phai dinh goc va u tim duoc truoc roi den v ma v phai qua u moi den parent cua u
				is_cut[u] = true;
			}
		} else low[u] = min(low[u], disc[v]);
	}
	// Check dinh goc
	if(par == -1 && child > 1) is_cut[u] = true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	for(int i = 1; i <= n; i++){
		if(!disc[i]) DFS(i, -1);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += (is_cut[i] == true);
	}
	cout << ans << ed;
	return BidenJr;
}

