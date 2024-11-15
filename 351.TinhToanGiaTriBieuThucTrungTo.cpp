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

ll calc(ll a, ll b, char c){
	switch(c){
	    case '+':
	    	return a + b;
	    case '-':
	    	return a - b;
	    case '*':
	    	return a * b;
	    case '/':
	    	return a / b;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<char> st;
		stack<ll> val;
		vector<string> v;
		for(int i = 0; i < s.size(); i++){
			if(isdigit(s[i])){
				ll num = 0;
				while(isdigit(s[i])){
				    num = num * 10 + (s[i] - '0');
				    i++;
				}
				i--;
				val.push(num);
			}
			else if(s[i] == '(') st.push(s[i]);
			else if(s[i] == ')'){
				while(!st.empty() && st.top() != '('){
					ll x1 = val.top(); val.pop();
					ll x2 = val.top(); val.pop();
					ll ans = calc(x2, x1, st.top());
					val.push(ans);
					st.pop();
				}
				st.pop();
			}
			else {
				while(!st.empty() && prior(st.top()) >= prior(s[i])){
					ll x1 = val.top(); val.pop();
					ll x2 = val.top(); val.pop();
					ll ans = calc(x2, x1, st.top());
					val.push(ans);
					st.pop();
				}
				st.push(s[i]);
			}
		}
		while(!st.empty()){
			ll x1 = val.top(); val.pop();
			ll x2 = val.top(); val.pop();
			ll ans = calc(x2, x1, st.top());
			val.push(ans);
			st.pop();
		}
		cout << val.top() << ed;
	}
	return BidenJr;
}
