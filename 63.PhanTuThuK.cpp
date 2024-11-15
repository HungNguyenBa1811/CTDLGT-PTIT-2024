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

vector<int> ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int m, n, k;
		cin >> m >> n >> k;
		int a[m], b[n];
		for(int i = 0; i < m; i++) cin >> a[i];
		for(int i = 0; i < n; i++) cin >> b[i];
		int i = 0, j = 0;
		while(i < m && j < n){
			if(a[i] <= b[j]){
				ans.push_back(a[i]);
				i++;
			} else {
				ans.push_back(b[j]);
				j++;	
			}
		}
		while(i < m){
			ans.push_back(a[i]);
			i++;
		}
		while(j < n){
			ans.push_back(b[j]);
			j++;
		}
		cout << ans[k - 1] << ed;
		ans.clear();
	}
	return BidenJr;
}
