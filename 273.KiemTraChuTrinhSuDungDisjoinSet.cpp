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

int n, m;
int parent[1001];
int sz[1001];

int find(int u){
	if(u == parent[u]) return u;
	return parent[u] = find(parent[u]); // Path Compression
}

bool Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return false;
	if(sz[a] < sz[b]) swap(a, b);
	parent[b] = a;
	sz[a] += sz[b];
	return true;
}

void ktao(){
	for(int i = 1; i <= n; i++){
		parent[i] = i;
		sz[i] = 1;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		ktao();
		bool ok = false;
		for(int i = 0; i < m; i++){
			int x, y;
			cin >> x >> y;
			if(!Union(x, y)){
				ok = true;
			}
		}
		if(ok) cout << "YES" << ed; // co chu trinh
		else cout << "NO" << ed;		
	}
	return BidenJr;
}
