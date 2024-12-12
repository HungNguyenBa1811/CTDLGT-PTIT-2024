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
		
		int l[n];
		l[0] = a[0];
		for(int i = 1; i < n; i++)
			l[i] = max(a[i], l[i - 1]);

		int r[n];
		r[n - 1] = a[n - 1];
		for(int i = n - 2; i >= 0; i--)
			r[i] = min(r[i + 1], a[i]);

		vector<int> v;
		for(int i = 0; i < n - 1; i++)
			if(l[i] <= r[i + 1])
				v.push_back(i + 1);
		
		cout << v.size() << ed;
		for(int x : v) cout << x << " ";
		cout << ed;
	}
	return BidenJr;
}

