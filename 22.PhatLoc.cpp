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

int n, ok;
int X[100];

void ktao(){
	for(int i = 1; i <= n; i++) X[i] = 0;
	X[1] = 1;
}

void sinh(){
	int i = n;
	while(i >= 1 && X[i] == 1){
		X[i] = 0;
		--i;
	}
	if(i == 0) ok = 0;
	else X[i] = 1;
}

int check(){
	if(X[n] == 1) return 0;
	for(int i = 1; i <= n - 1; i++){
		if(X[i] && X[i + 1]) return 0;
	}
	for(int i = 1; i <= n - 3; i++){
		if(!X[i] && !X[i + 1] && !X[i + 2] && !X[i + 3]) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	ktao();
	ok = 1;
	while(ok){
		if(check()){
			for(int i = 1; i <= n; i++){
				cout << ((X[i]) ? 8 : 6);
			}
			cout << ed;
		}
		sinh();
	}	
	return BidenJr;
}

