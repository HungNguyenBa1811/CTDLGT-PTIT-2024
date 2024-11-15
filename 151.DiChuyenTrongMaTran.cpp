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

int x_axis[] = {0, 1};
int y_axis[] = {1, 0};
vector<vector<int>> a(1001, vector<int>(1001));
vector<vector<bool>> visited(1001, vector<bool>(1001, false));
int m, n;

int BFS(){
	queue<pair<int, int>> q;
	q.push({0, 0});
	visited[0][0] = true;
	int cnt = 0;
	while(!q.empty()){
		int _qs = q.size();
		for(int asdf = 0; asdf < _qs; asdf++){
			int i = q.front().first;
			int j = q.front().second;
			q.pop();
			
			if(i == m - 1 && j == n - 1) return cnt;
			for(int k = 0; k < 2; k++){
				int _i = i + x_axis[k] * a[i][j];
				int _j = j + y_axis[k] * a[i][j];
				if(_i >= 0 && _i < m && _j >= 0 && _j < n && !visited[_i][_j]){
					visited[_i][_j] = true;
					q.push({_i, _j});
				}
			}
		}
		cnt++;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> m >> n;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
				visited[i][j] = false;
			}
		}
		cout << BFS() << ed;
	}
	return BidenJr;
}

