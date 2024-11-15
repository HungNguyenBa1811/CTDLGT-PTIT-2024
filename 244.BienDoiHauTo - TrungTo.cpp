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
		string s; cin >> s;
		stack<string> st;
		for(int i = 0; i < s.size(); i++){
			string tmp;
			if(isalpha(s[i])) tmp = s[i];
			else {
				string s1 = st.top(); st.pop();
				string s2 = st.top(); st.pop();
				tmp = '(' + s2 + s[i] + s1 + ')';
			}
			st.push(tmp);
		}
		cout << st.top() << ed;
	}
	return BidenJr;
}

