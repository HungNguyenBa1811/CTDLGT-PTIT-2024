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

/*
dp[pre][u]: chi phi tu u, trang thai pre
pre: so int co gtri = chuoi bit np la trang thai cua cac tp da chon
10110 => 1 3 4 da dc chon 
*/

int c[20][20], n, dp[1 << 21][21];

int Try(int pre, int u){
	if(u > n) return 0;
	if(dp[pre][u] != -1) return dp[pre][u];
	// cach chon: dich bit:
	// 010 => 0010 or 1010 => 00010 or 10010...
	int cmax = 0; // lon nhat
	int cur = 1 << n;
	for(int v = 1; v <= n; v++){
		cur >>= 1;
		if((pre & cur) != 0) continue;
		cmax = max(cmax, c[u][v] + Try(pre | cur, u + 1));
	}
	dp[pre][u] = cmax;
	return cmax;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				cin >> c[i][j];
		memset(dp, -1, sizeof(dp));
		cout << Try(0, 1) << ed;
	}
	return BidenJr;
}
