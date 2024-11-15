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

ll convert_base10(string a, int k){
	ll res = 0;
	reverse(begin(a), end(a));
	for(int i = 0; i < a.size(); i++){
		res += (a[i] - '0') * pow(k, i);
	}
	return res;
}

void convert_baseK(ll n, int k){
	if(n == 0) return;
	convert_baseK(n / k, k);
	cout << n % k;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int k;
		string a;
		string b;
		cin >> k >> a >> b;
		convert_baseK(convert_base10(a, k) + convert_base10(b, k), k);
		cout << ed;
	}
	return BidenJr;
}

