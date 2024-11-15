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

int a[505][505], n, m, f[505][505], ans;

void BFS(){
	queue<pair<int, int>> q;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == 2){
				q.push({i, j});
			}
		}
	}
	while(!q.empty()){
		pair<int, int> qtop = q.front(); q.pop();
		int i = qtop.first;
		int j = qtop.second;
		if(a[i][j] == 2){
			for(int k = 0; k < 4; k++){
				int i1 = i + x_4axis[k];
				int j1 = j + y_4axis[k];
				if(i1 > 0 && i1 <= n && j1 > 0 && j1 <= m && a[i1][j1] == 1){
					f[i1][j1] = f[i][j] + 1;
					a[i1][j1] = 2;
					q.push({i1, j1});
					ans = fmax(ans, f[i1][j1]);
				}
			}
		}
	}
}

int check(){
	for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 1) return 0;
        }
    }
    return 1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		memset(f, 0, sizeof(f));
		ans = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> a[i][j];
		BFS();
		if(check()) cout << ans << ed;
		else cout << -1 << ed;
	}
	return BidenJr;
}
