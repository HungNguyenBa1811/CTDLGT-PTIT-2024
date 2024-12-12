#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ed "\n"
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define BidenJr 0
int x_4axis[] = {0, 0, -1, 1};
int y_4axis[] = {-1, 1, 0, 0};
int x_8axis[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y_8axis[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int MOD = 1e9 + 7;

const int maxn = 1001;

int n, m;
int a[maxn][maxn];
int d[maxn][maxn];

void input(){
    cin >> n >> m;
    memset(d, 0, sizeof(d));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            d[i][j] = 1e9;
        }
    }
}

void dijkstra(int i, int j){
	d[i][j] = a[i][j];
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> Q;
	Q.push({0, {i, j}});
	while(!Q.empty()){
		pair<int, pair<int, int>> top = Q.top(); 
		Q.pop();
		i = top.second.first;
		j = top.second.second;
		int len = top.first;
		if(len > d[i][j]) continue;
		for(int k = 0; k < 4; k++){
			int i1 = i + x_4axis[k];
			int j1 = j + y_4axis[k];
			if(i1 > 0 && i1 <= n && j1 > 0 && j1 <= m)
			if(d[i1][j1] > d[i][j] + a[i1][j1]){
				d[i1][j1] = d[i][j] + a[i1][j1];
				Q.push({d[i1][j1], {i1, j1}});
			}
		}
	}
	cout << d[n][m] << ed;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		input();
        dijkstra(1, 1);
	}
	return BidenJr;
}
