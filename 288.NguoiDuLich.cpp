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

int n, c[20][20], X[20];
int visited[20];
int cmin = MOD, d = 0, ans = MOD;

void nhap(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> c[i][j];
			if(c[i][j]) cmin = fmin(cmin, c[i][j]);
		}
	}
	memset(visited, 0, sizeof(visited));
	X[1] = 1;
	visited[1] = 1;
}

void Try(int i){
	for(int j = 1; j <= n; j++){
		if(!visited[j]){
			visited[j] = 1;
			X[i] = j;
			d += c[X[i - 1]][X[i]];
			if(i == n){
				ans = fmin(ans, d + c[X[n]][1]);
			} else if(d + (n - i + 1) * cmin < ans){
				Try(i + 1);
			}
			visited[j] = 0;
			d -= c[X[i - 1]][X[i]];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	Try(2);
	cout << ans << ed;
	return BidenJr;
}

