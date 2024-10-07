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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a[n + 1];
		for(int i = 1; i <= n; i++) cin >> a[i];
		int l = 1, r = n, f = 0;
		while(l <= r){
			int mid = l + (r - l) / 2;
			if(a[mid] == k){
				cout << mid << ed;
				f = 1;
				break;
			} else if(a[mid] > k) r = mid - 1;
			else l = mid + 1;
		}
		if(!f) cout << "NO" << ed;
	}
	return BidenJr;
}

