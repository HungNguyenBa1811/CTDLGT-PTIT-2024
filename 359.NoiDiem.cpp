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

struct canh{
	int x, y; 
	double w;
};

vector<canh> dscanh;
int n, m;
int parent[1001];
int sz[1001];

int find(int u){
	if(u == parent[u]) return u;
	return parent[u] = find(parent[u]);
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

void input(){
	vector<pair<double, double>> v(105);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> v[i].first >> v[i].second;
	for(double i = 1; i < n; i++){
		for(double j = i + 1; j <= n; j++){
			double w = sqrt(1.0 * (v[i].first - v[j].first) * (v[i].first - v[j].first) + 1.0 * (v[i].second - v[j].second) * (v[i].second - v[j].second));
			dscanh.push_back({i, j, w});
		}
	}
	for(int i = 1; i <= n; i++){
		sz[i] = 1;
		parent[i] = i;		
	}
}

void kruskal(){
	sort(begin(dscanh), end(dscanh), [&](canh a, canh b) -> bool {
		return a.w < b.w;
	});
	double ans = 0;
	int cnt = 0;
	for(int i = 0; i < dscanh.size(); i++){
		if(cnt == n - 1) break;
		if(Union(dscanh[i].x, dscanh[i].y)){
			cnt++;
			ans += dscanh[i].w;
		}
	}
	cout << fixed << setprecision(6) << ans << ed;
	dscanh.clear();
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		input();
		kruskal();		
	}
	return BidenJr;
}
