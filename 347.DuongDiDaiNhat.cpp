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

int n, m, a[25][25], res;

void DFS(int u, int cnt){
	res = max(res, cnt);
	for(int v = 0; v < n; v++){
		if(a[u][v]){
			a[u][v] = a[v][u] = 0;
			DFS(v, cnt + 1);
			a[u][v] = a[v][u] = 1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		res = 0;
		memset(a, 0, sizeof(a));
		for(int i = 0; i < m; i++){
			int x, y;
			cin >> x >> y;
			a[x][y] = a[y][x] = 1;
		}
		for(int i = 0; i < n; i++){
			DFS(i, 0);
		}
		cout << res << ed;
	}
	return BidenJr;
}

