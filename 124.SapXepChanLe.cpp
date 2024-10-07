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
	int t = 1;
	while(t--){
		int n; cin >> n;
		vector<int> a;
		vector<int> b;
		for(int i = 1; i <= n; i++){
			int x; cin >> x;
			if(i % 2) a.push_back(x);
			else b.push_back(x);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end(), greater<int>());
		for(int i = 0, j = 0; i < a.size() || j < b.size(); i++, j++){
			cout << a[i] << " ";
			if(j < b.size()) cout << b[j] << " ";
		}
		cout << ed;
	}
	return BidenJr;
}

