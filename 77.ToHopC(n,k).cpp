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

ll nCk[1001][1001];

void sang(){
	for(int i = 0; i <= 1000; i++){
		for(int j = 0; j <= i; j++){
			if(i == j || j == 0) nCk[i][j] = 1;
			else {
				nCk[i][j] = nCk[i - 1][j] + nCk[i - 1][j - 1];
				nCk[i][j] %= MOD;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	sang();
	while(t--){
		int n, k;
		cin >> n >> k;
		cout << nCk[n][k] << ed;
	}
	return BidenJr;
}

