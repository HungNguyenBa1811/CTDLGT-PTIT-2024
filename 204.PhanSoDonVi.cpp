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

typedef struct PhanSo{
	ll tu, mau;
} PS;

void printPS(PS a){
	cout << a.tu << "/" << a.mau;
}

PS shorten(PS a){
	ll tmp = __gcd(a.tu, a.mau);
	a.tu /= tmp;
	a.mau /= tmp;
	return a;
}

PS subtract(PS a, PS b){
	PS x;
	x.tu = a.tu * b.mau - b.tu * a.mau;
	x.mau = a.mau * b.mau;
	x = shorten(x);
	return x;
}

PS process(PS x){
	PS a;
	a.tu = 1;
	a.mau = x.mau / x.tu;
	if(x.mau % x.tu != 0) a.mau++;
	printPS(a);
	a = subtract(x, a);
	a = shorten(a);
	return a;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		PS a;
		cin >> a.tu >> a.mau;
		shorten(a);
		int cnt = 0;
		while(a.tu != 0){
			if(cnt != 0){
				cout << " + ";
			} else {
				cnt++;
			}
			a = process(a);
		}
		cout << ed;
	}
	return BidenJr;
}

