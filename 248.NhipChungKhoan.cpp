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
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int res[n];
		stack<pair<int, int>> st; // gtri, vtri
		for(int i = 0; i < n; i++){
			while(!st.empty() && st.top().first <= a[i]){
				st.pop();
			}
			res[i] = (st.empty()) ? i + 1 : i - st.top().second;
			st.push({a[i], i});
		}
		for(int i = 0; i < n; i++) cout << res[i] << " ";
		cout << ed;
	}
	return BidenJr;
}

