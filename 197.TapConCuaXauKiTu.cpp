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

int n;
string s;
string res = "";
vector<string> ans;

void Try(int cnt){
	if(cnt == n){
	  string tmp = "";
		for(int i = 0; i < n; i++){
		  if(res[i] - '0') tmp += s[i];
		}
		if(tmp.size()) ans.push_back(tmp);
		return;
	}
	for(int i = 0; i <= 1; i++){
		res += '0' + i;
		Try(cnt + 1);
		res.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n >> s;
		Try(0);
		sort(ans.begin(), ans.end());
		for(string x : ans) cout << x << " ";
		cout << ed;
		ans.clear();
	}
	return BidenJr;
}

