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

ll a[55];
int find(int idx, ll n, ll i){
    if(idx == 1) return n & 1;
    ll tmp = a[idx - 1];
    if(i == tmp + 1) return n & 1;
    if(i < tmp + 1) return find(idx - 1, n >> 1, i);
    return find(idx - 1, n >> 1, i - tmp - 1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
    	ll n, l, r, tmp;
        cin >> n >> l >> r;
        memset(a, 0, sizeof(a));
        a[1] = 1;
        tmp = n;
        n >>= 1;
        int idx = 2;
        while(n > 0){
            a[idx] = (a[idx - 1] << 1) + 1;
            n >>= 1;
            idx++;
        }
        idx--;
        ll res = 0;
        for(ll i = l; i <= r; i++) res += find(idx, tmp, i);
        cout << res << ed;
    }
	return BidenJr;
}

