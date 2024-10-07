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
        pair<int, int> a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a, a + n);
        int ans = -1, cmin = a[0].second, k = a[0].first;
        for(int i = 1; i < n; i++){
            if(a[i].first > k) ans = max(ans, a[i].second - cmin);
            if(cmin > a[i].second){
                cmin = a[i].second;
                k = a[i].first;
            }
        }
        cout << ans << ed;
	}
	return BidenJr;
}

