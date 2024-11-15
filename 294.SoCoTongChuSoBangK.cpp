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

ll dp[105][50005];

void sieve(){
    // dp[i][j]: so co i chu so va tong chu so = k
    memset(dp , 0 , sizeof(dp));
    for(int i = 1; i <= 9; i++)
        dp[1][i] = 1;
    for(int i = 1; i <= 100; i++)
        for(int j = 0; j <= 9; j++)
            for(int k = j; k <= 50000; k++)
                dp[i][k] = (dp[i][k] + dp[i - 1][k - j]) % MOD;
				// chen them 1 chu so vao so i - 1
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();
    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        cout << dp[n][k] << ed;
    }
    return BidenJr;
}
