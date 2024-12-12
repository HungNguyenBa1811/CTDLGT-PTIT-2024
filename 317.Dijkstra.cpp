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

// Dijkstra

// DK: cac canh khong am

// S: source
// D: chi phi ngan nhat tu S

// B1:
// - Gan chi phi duong di cho moi dinh
// - d[s] = 0
// B2: lap
//while(!Q.empty()){
//	// Chon dinh co chi phi nho nhat (u)
//	// Xoa khoi PQ (PQ sort theo chi phi ngan nhat)
//	// Relaxation: Duyet moi dinh ke voi u va cap nhat duong di ngan nhat:
//	d[v] = min(d[v], d[u] + (u, v))
//}

const int maxn = 1001;

int n, m, k;
vector<pair<int, int>> ke[maxn];
int d[maxn];

void input(){
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		ke[x].push_back({y, w});
		ke[y].push_back({x, w});
	}
}

void dijkstra(int s){
	for(int i = 1; i <= n; i++) d[i] = 1e9;
	d[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	Q.push({0, s});
	while(!Q.empty()){
		pair<int, int> top = Q.top(); 
		Q.pop();
		int u = top.second;
		int len = top.first;
		if(len > d[u]) continue;
		for(pair<int, int> it : ke[u]){
			int v = it.first;
			int w = it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
			}
		}
	}
	for(int i = 1; i <= n; i++) cout << d[i] << " ";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		input();
		dijkstra(k);
		cout << ed;
		for(int i = 1; i <= n; i++) ke[i].clear();
	}

	return BidenJr;
}
