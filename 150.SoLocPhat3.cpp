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
		queue<string> q;
		vector<string> ans;
		string s;
		q.push("6"); ans.push_back("6");
		q.push("8"); ans.push_back("8");
		while(1){
			s = q.front(); q.pop();
			if(s.size() == n) break;
			q.push(s + "6"); ans.push_back(s + "6");
			q.push(s + "8"); ans.push_back(s + "8");
		}
		cout << ans.size() << ed;
		reverse(ans.begin(), ans.end());
		for(string x : ans) cout << x << " ";
		cout << ed;
	}
	return BidenJr;
}

