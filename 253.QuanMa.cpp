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
int knightX[] = {-2, -2, -1, -1, +1, +1, +2, +2};
int knightY[] = {-1, +1, -2, +2, -2, +2, -1, +1};
const int MOD = 1e9 + 7;

vector<int> ke(1001);
bool visited[1001][1001];
string s1;
string s2;

void input(){
	cin >> s1 >> s2;
	memset(visited, false, sizeof(visited));
}

int BFS(int i, int j, int x, int y){
  if(i == x && j == y) return 0;
	queue<pair<pair<int, int>, int>> q;
	q.push({{i, j}, 0});
	visited[i][j] = 1;
	while(!q.empty()){
		pair<pair<int, int>, int> qtop = q.front();
		if(qtop.first.first == x && qtop.first.second == y) return qtop.second;
		q.pop();
		for(int k = 0; k < 8; k++){
			int i1 = qtop.first.first + knightX[k];
			int j1 = qtop.first.second + knightY[k];
			int cnt = qtop.second;
			if(i1 > 0 && i1 <= 8 && j1 > 0 && j1 <= 8 && !visited[i1][j1]){
				visited[i1][j1] = true;
				q.push({{i1, j1}, cnt + 1});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		input();
		cout << BFS(s1[0] - 'a' + 1, s1[1] - '0', s2[0] - 'a' + 1, s2[1] - '0') << ed;
	}
	return BidenJr;
}

