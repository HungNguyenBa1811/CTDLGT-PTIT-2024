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

ll a[1005], b[1005], dp[1005];

ll Mul(ll a, ll b, ll m){
    a %= m;
    b %= m;
    ll tmp = 1.0 * a * b / m;
    return (a * b - tmp * m);
}

ll Pow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b % 2) res = Mul(res, a, MOD);
        a = Mul(a, a, MOD);
        b >>= 1;
    }
    return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
    	ll n, k;
        cin >> n >> k;
        a[0] = b[k + 3] = dp[0] = 1;
        ll tmp = k + 2;
        for(int i = 1; i <= tmp; i++){
            a[i] = Mul(a[i - 1], n - i, MOD);
            b[tmp - i + 1] = Mul(b[tmp - i + 2], n - (tmp - i + 1), MOD);
            dp[i] = Mul(dp[i - 1], i, MOD);
        }
        ll sum = 0, res = 0;
        for(int i = 1; i <= tmp; i++){
            sum += Pow(i, k);
            sum %= MOD;
            ll x = Mul(sum, a[i - 1], MOD);
            ll y = Mul(dp[i - 1], dp[k + 2 - i], MOD);
            ll z = Mul(b[i + 1], Pow(Mul(y, ((k - i) & 1) ? -1 : 1, MOD), MOD - 2), MOD);
            res = (res + Mul(x, z, MOD)) % MOD;
        }
        cout << (res + MOD) % MOD << ed;
    }
	return BidenJr;
}

