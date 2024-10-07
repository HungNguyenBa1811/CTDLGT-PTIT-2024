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

int a[101][101];
int m, n, cnt;

void Try(int i, int j){
	if(i == m && j == n){
		cnt++;
		return;
	}
	if(i + 1 <= m) Try(i + 1, j);
	if(j + 1 <= n) Try(i, j + 1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> m >> n;
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= n; j++)
				cin >> a[i][j];
		cnt = 0;
		if(a[1][1]) Try(1, 1);
		cout << cnt << ed;
	}
	return BidenJr;
}
