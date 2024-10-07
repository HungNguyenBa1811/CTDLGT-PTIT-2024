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

int n, k, ok;
int X[1001];
ll C[16][16];
void nCk(){
	for(int i = 0; i <= 15; i++){
		for(int j = 0; j <= i; j++){
			if(i == j || j == 0) C[i][j] = 1;
			else {
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
				C[i][j] %= MOD;
			}
		}
	}
}

void sinh(){
	int i = k;
	while(i >= 1 && X[i] == n - k + i){
		--i;
	}
	if(i == 0) ok = 0;
	else {
		X[i]++;
		for(int j = i + 1; j <= k; j++){
			X[j] = X[j - 1] + 1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	nCk();
	while(t--){
		cin >> n >> k;
		int cnt = 0;
		for(int i = 1; i <= k; i++){
			cin >> X[i];
		}
		ok = 1;
		do {
			cnt++;
			sinh();
		} while (ok);
		cout << C[n][k] - cnt + 1 << ed;
	}
	return BidenJr;
}
