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

char a[105][105];
int n, _x, _y, _u, _v;

int BFS(int x, int y, int u, int v){
	queue<pair<pair<int, int>, int>> q;
	q.push({{x, y}, 0});
	a[x][y] = 'X';
	while(!q.empty()){
		pair<pair<int, int>, int> qtop = q.front(); q.pop();
		int i = qtop.first.first;
		int j = qtop.first.second;
		int cnt = qtop.second;
		if(i == u && j == v) return cnt;
		for(int idx = 0; idx < 4; idx++){
			int i1 = i + x_4axis[idx];
			int j1 = j + y_4axis[idx];
			while(i1 > 0 && i1 <= n && j1 > 0 && j1 <= n && a[i1][j1] == '.'){
				q.push({{i1, j1}, cnt + 1});
				a[i1][j1] = 'X';
					i1 + x_4axis[idx];
					j1 + y_4axis[idx];
			}
		}
	}
	return -1;
}

void input(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
				cin >> a[i][j];
	cin >> _x >> _y >> _u >> _v;
}

void solve(){
	cout << BFS(_x + 1, _y + 1, _u + 1, _v + 1) << ed;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		input();
		solve();
	}
	return BidenJr;
}
