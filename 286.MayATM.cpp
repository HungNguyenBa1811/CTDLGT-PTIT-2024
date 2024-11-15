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

// Idea: Duyet quay lui, thu lan luot voi 1,2,3,..n to tien xem co tong bang s khong, gap tong bang s thi ngat nhanh can
int n, check[35];
ll s, sum, a[35];
bool ok;

void Try(int i, int j){
	if(i == j){
		if(sum == s) ok = true;
		return;
	}
	for(int k = 1; k <= n; k++){
		if(k > check[i - 1]){
			sum += a[k];
			check[i] = k;
			if(sum <= s) Try(i + 1, j);
			sum -= a[k];
			check[i] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n >> s;
		for(int i = 1; i <= n; i++) cin >> a[i];
		ok = false;
		int i;
		for(i = 1; i <= n; i++){
			Try(0, i);
			if(ok) break;
		}
		if(ok) cout << i << ed;
		else cout << -1 << ed;
	}
	return BidenJr;
}

