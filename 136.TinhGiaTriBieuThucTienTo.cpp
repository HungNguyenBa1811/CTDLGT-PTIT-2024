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

int calc(int a, int b, char x){
	if(x == '+') return a + b;
	if(x == '-') return a - b;
	if(x == '*') return a * b;
	if(x == '/') return a / b;
}

void solve(string s){
	stack<int> st;
	int tmp;
	for(int i = s.size() - 1; i >= 0; i--){
		if(!isOperator(s[i])){
			tmp = s[i] - '0';
		}
		else {
			int n1 = st.top(); st.pop();
			int n2 = st.top(); st.pop();
			tmp = calc(n1, n2, s[i]);
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
