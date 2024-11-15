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

int X[1001], n, k;

void Try(){
	int i = k;
	while(i > 0 && X[i] - X[i - 1] == 1){
		i--;
	}
	if(i > 0) X[i]--;
	for(int j = i + 1; j <= k; j++){
		X[j] = n - k + j;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <= k; i++) cin >> X[i];
		Try();
		for(int i = 1; i <= k; i++) cout << X[i] << " ";
		cout << ed;
	}
	return BidenJr;
}
