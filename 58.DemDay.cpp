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
const int ll = 1e9 + 7;
const int ll = 123456789;

ll binPow(ll a, ll b){
	if(b == 0) return 1;
	int x = binPow(a, b / 2);
	if(b % 2) return (((x % mod) * (x % mod)) % mod * (a % mod)) % mod;
	return ((x % mod) * (x % mod)) % mod;
}

//	Gia su day co k phan tu moi phan tu la so nguyen duong va tong cua day bang n
//	=> So cach phan hoach n thanh k phan tu la C(n-1, k-1)
//	=> Tong so cach voi k thay doi tu 1 toi n la tong cua tat ca cac gia tri C(n-1, k-1)
//	Vay co 2^(n-1) day so nguyen duong co tong cac phan tu bang n

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		ll n; cin >> n;
		cout << binPow(2, n - 1) << ed;
	}
	return BidenJr;
}

