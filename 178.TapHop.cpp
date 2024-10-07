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

int X[101], n, k, s, ok, cnt;

void ktao(){
	for(int i = 1; i <= k; i++) X[i] = i;
	ok = 1;
	cnt = 0;
}

void sinh(){
	int i = k;
	while(i >= 1 && X[i] == n - k + i){
		--i;
	}
	if(i == 0) ok = false;
	else {
		X[i]++;
		for(int j = i + 1; j <= k; j++){
			X[j] = X[j - 1] + 1;
		}
	}
}

int check(){
	int tmp = 0;
	for(int i = 1; i <= k; i++) tmp += X[i];
	return tmp == s;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(1){
		cin >> n >> k >> s;
		if(n == 0 && k == 0 && s == 0) break;
		if(k > n){
		    cout << 0 << ed;
		    continue;
		}
		ktao();
		while(ok){
			if(check()) cnt++;
			sinh();
		}
		cout << cnt << ed;
	}
	return BidenJr;
}
