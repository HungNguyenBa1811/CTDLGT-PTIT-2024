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
		int n; cin >> n;
		int a[n], dpl[n] = {}, dpr[n] = {};
		dpl[0] = dpr[n - 1] = 1;
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 1; i < n; i++){
			if(a[i - 1] < a[i]) dpl[i] = dpl[i - 1] + 1;
			else dpl[i] = 1;
		}
		for(int i = n - 2; i >= 0; i--){
			if(a[i] > a[i + 1]) dpr[i] = dpr[i + 1] + 1;
			else dpr[i] = 1;
		}
		int ans = 0;
		for(int i = 0; i < n; i++) ans = fmax(ans, dpl[i] + dpr[i] - 1);
		cout << ans << ed;
	}
	return BidenJr;
}

