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

struct fence{
	int x, y, z, t;
    bool operator < (const fence& other) const {
		if(x != other.x) return x < other.x;
		if(y != other.y) return y < other.y;
		if(z != other.z) return z < other.z;
		return t < other.t;
    }
};

const int maxn = 1005;
int n, m, k;
set<fence> se;
int a[maxn][maxn];
bool visited[maxn][maxn];
vector<int> v;

void input(){
	memset(visited, 0, sizeof(visited));
	memset(a, 0, sizeof(a));
	se.clear();
	v.clear();
	cin >> n >> k >> m;
	for(int i = 0; i < m; i++){
		int x, y, z, t;
		cin >> x >> y >> z >> t;
		if(x > z || (x == z && y > t)){
		    swap(x, z);
		    swap(y, t);
		}
		se.insert({x, y, z, t});
	}
	for(int i = 0; i < k; i++){
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
	}
}

void BFS(int i, int j){
	queue<pair<int, int>> q;
	q.push({i, j});
	int cnt = 1;
	visited[i][j] = true;
	while(!q.empty()){
		pair<int, int> tmp = q.front();
		q.pop();
		for(int id = 0; id < 4; id++){
			int i1 = tmp.first + x_4axis[id];
			int j1 = tmp.second + y_4axis[id];
			if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && !visited[i1][j1]){
				if(se.count({min(i1, tmp.first), min(j1, tmp.second), max(i1, tmp.first), max(j1, tmp.second)}) > 0){
					continue;
				}
				if(a[i1][j1]) cnt++;
				visited[i1][j1] = true;
				q.push({i1, j1});
			}
		}
	}
	v.push_back(cnt);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(a[i][j] && !visited[i][j])
				BFS(i, j);
	ll ans = 0;
    for(int i = 0; i < v.size() - 1; i++){  
        for(int j = i + 1; j < v.size(); j++){
            ans += 1ll * v[i] * v[j];
        }
    }
    cout << ans << ed;
	return BidenJr;
}
