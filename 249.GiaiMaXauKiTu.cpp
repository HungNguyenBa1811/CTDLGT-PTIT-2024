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

void solve(string s){
	stack<int> heso;
	stack<string> st;
	int tmp = 0;
	for(int i = 0; i < s.size(); i++){
		if(isdigit(s[i])){
			tmp = tmp * 10 + s[i] - '0';
		} else if(s[i] == '['){
			if(tmp == 0) tmp = 1;
			heso.push(tmp);
			tmp = 0;
			st.push("[");
		} else if(s[i] == ']'){
			string x = "";
			while(!st.empty() && st.top() != "["){
				x = st.top() + x;
				st.pop();
			}
			st.pop();
			string ans = "";
			for(int i = 0; i < heso.top(); i++) ans += x;
			heso.pop();
			st.push(ans);
		} else {
		  string g = "";
		  g += s[i];
			st.push(g);
		}
	}
	string res = "";
	while(!st.empty()){
		res = st.top() + res;
		st.pop();
	}
	cout << res << ed;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		string s;
		cin >> s;
		solve(s);
	}
	return BidenJr;
}
