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

int cnt[5];

int find(int a[], int l, int r, int x){
	int res = -1 ;
	while(l <= r){
		int mid = l + (r - l) / 2;
		if(a[mid] > x){
			res = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	return res;
}

int solve(int a[], int n, int x){
	if(x == 0) return 0;
	if(x == 1) return cnt[0];
	int res = cnt[0] + cnt[1];
	int i1 = find(a, 0, n - 1, x);
	if(i1 != -1) res += n - i1;
	if(x == 2) res -= (cnt[3] + cnt[4]);
	if(x == 3) res += cnt[2];
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n, m; 
		cin >> n >> m;
		memset(cnt, 0, sizeof(cnt));
		int a[n], b[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < m; i++){
			cin >> b[i];
			if(b[i] <= 4) cnt[b[i]]++;
		}
		sort(b, b + m);
		ll ans = 0;
		for(int i = 0; i < n; i++) ans += solve(b, m, a[i]);
		cout << ans << ed;
	}
	return BidenJr;
}
