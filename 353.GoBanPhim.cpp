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
	string s; cin >> s;
	string ft;
	stack<char> bk;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '>'){
			if(!bk.empty()){
				ft.push_back(bk.top());
				bk.pop();
			}
		} else if(s[i] == '<'){
			if(!ft.empty()){
				bk.push(ft[ft.size() - 1]);
				ft.pop_back();
			}
		} else if(s[i] == '-'){
			if(!ft.empty()){
				ft.pop_back();
			}
		} else {
			ft.push_back(s[i]);
		}
	}
	while(!bk.empty()){
		ft += bk.top();
		bk.pop();
	}
	cout << ft;
	return BidenJr;
}
