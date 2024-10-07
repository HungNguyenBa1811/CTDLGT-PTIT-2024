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
	stack<int> st;
	while(t--){
		string s; cin >> s;
		if(s == "PUSH"){
			int n; cin >> n;
			st.push(n);
		} else if(s == "POP"){
			if(!st.empty()) st.pop();
		} else if(s == "PRINT"){
			if(!st.empty()) cout << st.top();
			else cout << "NONE";
			cout << ed;
		}
	}
	return BidenJr;
}

