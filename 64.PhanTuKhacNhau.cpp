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

int a[1000001], b[1000001];

int solve(int l, int r){
	if(l == r) return l;
	int mid = l + (r - l) / 2;
	if(a[mid] == b[mid]) return solve(mid + 1, r);
	return solve(l, mid);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n - 1; i++) cin >> b[i];
		cout << solve(0, n - 1) + 1 << ed;
	}
	return BidenJr;
}
