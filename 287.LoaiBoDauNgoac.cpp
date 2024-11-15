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

int max_len;
map<string, int> mp;

int check(string s){
	if(s.size() < 2) return 0;
	stack<char> st;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '(') st.push(s[i]);
		else if(s[i] == ')'){
			if(st.empty()) return 0;
			st.pop();
		}
	}
	return st.empty();
}

void Try(string s, int i){
	if(s.size() < max_len) return;
	if(check(s)){
		if(s.size() > max_len){
			max_len = s.size();
			mp.clear();
		}
		mp[s] = 1;
		return;
	}
	for(int j = i; j < s.size(); j++){
		if(s[j] == '(' || s[j] == ')'){
			string tmp = s;
			tmp.erase(j, 1);
			Try(tmp, j);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		max_len = 0;
		mp.clear();
		Try(s, 0);
		if(!mp.size()) cout << -1 << ed;
		else {
			for(auto x : mp) cout << x.first << " ";
			cout << ed;
		}
	}
	return BidenJr;
}
