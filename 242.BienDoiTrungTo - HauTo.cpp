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

int prior(char x){
	switch(x){
		case '^':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return -1;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<char> st;
		for(int i = 0; i < s.size(); i++){
			if(isalpha(s[i])) cout << s[i];
			else if(s[i] == '(') st.push(s[i]);
			else if(s[i] == ')'){
				while(!st.empty() && st.top() != '('){
					cout << st.top();
					st.pop();
				}
				st.pop();
			}
			else {
				while(!st.empty() && prior(st.top()) >= prior(s[i])){
					cout << st.top();
					st.pop();
				}
				st.push(s[i]);
			}
		}
		while(!st.empty()){
			if(st.top() != '(') cout << st.top();
			st.pop();
		}
		cout << ed;
	}
	return BidenJr;
}

