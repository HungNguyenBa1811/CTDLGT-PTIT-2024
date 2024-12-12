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

ll a[11], f[101];

void sieve(){
	for (int i = 1; i <= 10; i++)
        a[i] = 1;
    f[1] = 10;
    for(int i = 2; i <= 100; i++){
        for (int j = 1; j <= 9; j++) {
            ll s = 0;
            for (int k = j; k <= 9; ++k)
                s += a[k];
            a[j] = s;
            f[i] = (f[i] + s) % MOD;
        }
    }
    for(int i = 2; i <= 100; i++)
		f[i] = (f[i] + f[i - 1]) % MOD;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	sieve();
	while(t--){
		int n; cin >> n;
		cout << f[n] << ed;
	}
	return BidenJr;
}

