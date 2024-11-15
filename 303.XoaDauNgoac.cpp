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

string a;
int n, m[205], X[205];
set<string> se;

void Try(int i, int pos){
	if(i){
		string s = "";
		for(int j=0; j<n; j++){
			if(!X[j]) s += a[j];
		}
		se.insert(s);
	}
	for(int j = pos; j < n; j++){
		if(a[j] == '('){
			if(!X[j]){
				X[j] = X[m[j]] = 1;
				Try(i + 1, i + 1);
				X[j] = X[m[j]] = 0;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a;
	n = a.size();
	memset(m, 0, sizeof(m));
	stack<int> st;
	for(int i=0; i<n; i++){
		if(a[i] == '('){
			st.push(i);
		} else if(a[i] == ')'){
			m[st.top()] = i;
			st.pop();
		}
	}
	Try(0, 0);
	for(auto &i : se) cout << i << ed;
	return BidenJr;
}

