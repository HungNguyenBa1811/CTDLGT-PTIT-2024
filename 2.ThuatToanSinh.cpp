#include <bits/stdc++.h>
#include <limits>
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

int X[1001];
int n, ok;

void ktao(){
	for(int i = 1; i <= n; i++) X[i] = 0;
}

void in(){
	for(int i = 1; i <= n; i++) cout << X[i] << ' ';
}

void in_reverse(){
	for(int i = n; i >= 1; i--) cout << X[i] << ' ';
}

void sinh(){
	int i = n;
	while(i > 0 && X[i]){
		X[i] = 0;
		i--;
	}
	if(i == 0) ok = 0;
	else X[i] = 1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int nnai = n % 2;
	n /= 2;
	ktao();
	ok = 1;
	while(ok){
		if(nnai){
			in();
			cout << 0;
			in_reverse();
			cout << ed;
			in();
			cout << 1;
			in_reverse();
		} else {
			in();
			in_reverse();
		}
		cout << ed;
		sinh();
	}
	return BidenJr;
}
