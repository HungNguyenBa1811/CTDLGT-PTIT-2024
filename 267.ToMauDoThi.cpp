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
int color[1001];
int n, m, c, ok;

void input(){
	cin >> n >> m >> c;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	memset(color, 0, sizeof(color));
}

bool check(int u, int k){
	for(int v : ke[u])
		if(color[v] == k)
			return false;
	return true;
}

void Try(int u){
	if(ok) return;
	for(int i = 1; i <= c; i++){
		if(check(u, i)){
			color[u] = i;
			if(u == n){
				ok = 1;
				return;
			} else Try(u + 1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		input();
		ok = 0;
		Try(1);
		cout << ((ok) ? "YES" : "NO") << ed;
		for(int i = 1; i <= n; i++) ke[i].clear();		
	}
	return BidenJr;
}
