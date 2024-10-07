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
		vector<string> v;
		v.push_back("0");
		v.push_back("1");
		for(int i = 2; i <= n; i++){
			for(int j = v.size() - 1; j >= 0; j--){
				v.push_back("1" + v[j]);
				v[j] = "0" + v[j];
			}
		}
		for(string s : v) cout << s << " ";
		cout << ed;
	}
	return BidenJr;
}
