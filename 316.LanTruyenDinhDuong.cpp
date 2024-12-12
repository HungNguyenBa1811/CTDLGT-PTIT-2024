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

const int maxn = 200001;
vector<int> ke[maxn];
int n, d[maxn];
ll dp[maxn], used[maxn];

void DFS(int u){
	dp[u] = d[u];
	used[u] = 1;
	for(int v : ke[u]){
		DFS(v);
		dp[u] += dp[v];
		used[u] += used[v];
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 2; i <= n; i++){
		int x; cin >> x;
		ke[x].push_back(i);
		d[i] = d[x] + 1;
	}
	DFS(1);
	for(int i = 1; i <= n; i++)
		cout << dp[i] - used[i] * (d[i] - 1) << " ";
	return BidenJr;
}

