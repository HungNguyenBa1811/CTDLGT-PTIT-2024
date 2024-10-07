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

int n, k, check;
int a[101];

void Try(int i, int s){
	if(s == k){
		check = 1;
		return;
	}
	if(s > k || i > n || check) return;
	Try(i + 1, s + a[i]);
	Try(i + 1, s);
}

void solve(){
	int sum = 0;
	for(int i = 0; i < n; i++) sum += a[i];
	if(sum % 2){
		cout << "NO" << ed;
		return;
	}
	k = sum / 2;
	Try(0, 0);
	if(check) cout << "YES" << ed;
	else cout << "NO" << ed;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		check = 0;
		solve();
	}
	return BidenJr;
}
