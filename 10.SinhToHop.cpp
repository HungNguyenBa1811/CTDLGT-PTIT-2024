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

int X[101], n, k;
bool ok;

// khoi tao
void ktao(){
	for(int i = 1; i <= k; i++){
		X[i] = i;
	}
}

// 1 4 5 7 8
// 1 4 5 7 9
// 1 4 5 8 9
// 1 4 6 7 8

// sinh
void sinh(){
	int i = k;
	// 1 4 5
	// 2 3 4
	// 2 3 5
	// 2 4 5
	// 3 4 5
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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		ok = true;
		ktao();
		while(ok){
			for(int i = 1; i <= k; i++){
				cout << X[i];
			}
			cout << " ";
			sinh();
		}
		cout << ed;
	}
	return BidenJr;
}

