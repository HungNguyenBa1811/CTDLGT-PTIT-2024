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
	    int f[n], ans = 0;
	    pair<double, double> a[n];
	    for(int i = 0; i < n; i++){
	        f[i] = 1;
	        cin >> a[i].first >> a[i].second;
	        for(int j = 0; j < i; j++)
	            if(a[i].first > a[j].first && a[i].second < a[j].second && f[i] <= f[j])
	                f[i] = f[j] + 1;
	        ans = max(ans, f[i]);
	    }
	    cout << ans << ed;
	}
	return BidenJr;
}

