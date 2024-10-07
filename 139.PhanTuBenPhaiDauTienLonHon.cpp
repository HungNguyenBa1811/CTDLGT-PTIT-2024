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
		int a[n], ans[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		stack<int> st;
		for(int i = n - 1; i >= 0; i--){
			while(!st.empty() && st.top() <= a[i]){
				st.pop();
			}
			ans[i] = (!st.empty()) ? st.top() : -1;
			st.push(a[i]);
		}
		for(int i = 0; i < n; i++) cout << ans[i] << " ";
		cout << ed;
	}
	return BidenJr;
}

