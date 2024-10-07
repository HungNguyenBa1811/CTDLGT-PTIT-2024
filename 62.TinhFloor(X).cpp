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

int search(int a[], int n, int k){
	int l = 0, r = n - 1, ans = -2;
	while(l <= r){
		int mid = l + (r - l) / 2;
		if(a[mid] > k) r = mid - 1;
		else {
			ans = mid;
			l = mid + 1;
		}
	}
	return ans + 1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		cout << search(a, n, k) << ed;
	}
	return BidenJr;
}

