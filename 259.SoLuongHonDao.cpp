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
int a[505][505];

void input(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
}

void DFS(int i, int j){
	a[i][j] = 0;
	for(int x = 0; x < 8; x++){
		int i1 = i + x_8axis[x];
		int j1 = j + y_8axis[x];
		if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1]){
			DFS(i1, j1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		input();
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(a[i][j]){
					cnt++;
					DFS(i, j);
				}				
			}
		}
		cout << cnt << ed;	
	}
	return BidenJr;
}

