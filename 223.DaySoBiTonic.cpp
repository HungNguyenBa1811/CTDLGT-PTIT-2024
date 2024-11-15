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
		int a[n], dp1[n] = {0}, dp2[n] = {0};
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++){
			dp1[i] = a[i];
			for(int j = 0; j < i; j++){
				if(a[i] > a[j]){
					dp1[i] = fmax(dp1[i], dp1[j] + a[i]);
				}
			}
		}
		for(int i = n - 1; i >= 0; i--){
			dp2[i] = a[i];
			for(int j = n - 1; j > i; j--){
				if(a[i] > a[j]){
					dp2[i] = fmax(dp2[i], dp2[j] + a[i]);
				}
			}
		}
		int cmax = 0;
		for(int i = 0; i < n; i++){
			cmax = fmax(cmax, dp1[i] + dp2[i] - a[i]);
		}
		cout << cmax << ed;
	}
	return BidenJr;
}
