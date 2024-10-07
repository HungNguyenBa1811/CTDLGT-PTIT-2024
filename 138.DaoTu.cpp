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
	int t; cin >> t; cin.ignore();
	while(t--){
		string s; getline(cin, s);
		stringstream ss(s);
		string w;
		stack<string> st;
		while(ss >> w){
			st.push(w);
		}
		while(!st.empty()){
			cout << st.top() << " ";
			st.pop();
		}
		cout << ed;
	}
	return BidenJr;
}

