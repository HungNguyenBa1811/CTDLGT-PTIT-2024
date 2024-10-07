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

int a[1001];
int n, k, ok;
string s;
vector<string> res;

void Try(int i, int sum){
  if(i > n) return;
  if(sum > k) return;
	if(sum == k){
		res.push_back(s);
		ok = 1;
		return;
	}
	string tmp = to_string(a[i]);
	s += tmp;
	s += " ";
	Try(i + 1, sum + a[i]);
	for(int i = 0; i <= tmp.size(); i++) s.pop_back();
	Try(i + 1, sum);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 0; i < n; i++) cin >> a[i];
		ok = 0;
		sort(a, a + n);
		Try(0, 0);
//		sort(res.begin(), res.end());
		for(string w : res){
			cout << "[";
			for(int i = 0; i < w.size() - 1; i++){
				cout << w[i]; 
			}
			cout << "] ";
		}
		res.clear();
		if(!ok) cout << -1;
		cout << ed;
	}
	return BidenJr;
}
