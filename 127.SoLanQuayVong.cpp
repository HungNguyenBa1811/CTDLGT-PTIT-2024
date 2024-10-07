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
		int n, k, f = 1;
		int ans = 0;
		cin >> n;
		vector<int> a;
		vector<int> b;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			if(i != 0 && x < a[i - 1]) f = 0;
			if(f) a.push_back(x);
			else b.push_back(x);
		}
		if(b.size() == 0) cout << 0 << ed;
		else cout << a.size() << ed;
	}
	return BidenJr;
}

