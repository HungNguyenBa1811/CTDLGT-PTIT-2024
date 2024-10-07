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

bool isOperator(char x){
	return (x == '+' || x == '-' || x == '*' || x == '/');
}

void solve(string s){
	int n = s.size();
	stack<string> st;
	string tmp;
	for(int i = n - 1; i >= 0; i--){
		if(!isOperator(s[i])) tmp = s[i];
		else {
			string s1 = st.top(); st.pop();
			string s2 = st.top(); st.pop();
			tmp = s1 + s2 + s[i];
		}
		st.push(tmp);
	}
	cout << st.top() << ed;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		solve(s);
	}
	return BidenJr;
}

