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

char c[1001][1001];
int n, m;

void nhap(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> c[i][j];
}

void DFS(int i, int j){
	c[i][j] = '.';
	for(int k = 0; k < 8; k++){
		int i1 = i + x_8axis[k];
		int j1 = j + y_8axis[k];
		if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && c[i1][j1] == 'W'){
			DFS(i1, j1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int ans = 0;
	nhap();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(c[i][j] == 'W'){
				ans++;
				DFS(i, j);
			}
		}
	}
	cout << ans << ed;	
	return BidenJr;
}
