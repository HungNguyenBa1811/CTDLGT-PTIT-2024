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

// P(n, k) = P(n-1, k) + k*P(n-1, k-1)
ll p[1001][1001] = {1};

void sieve(){
    for(int i = 1; i <= 1000; i++)
        p[i][1] = i;
    for(int i = 2; i <= 1000; i++)
        for(int j = 2; j <= i; j++)
            p[i][j] = i * p[i - 1][j - 1] % MOD;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	sieve();
	while(t--){
		int n, k;
		cin >> n >> k;
		cout << p[n][k] << ed;
	}
	return BidenJr;
}

