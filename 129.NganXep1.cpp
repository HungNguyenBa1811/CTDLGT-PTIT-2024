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

ll str_int(string s){
	ll n = 0;
	for(char x : s) n = n * 10 + (x - '0');
	return n;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	vector<int> st;
	while(getline(cin, s)){
		stringstream ss(s);
		string w;
		string tmp;
		int f = 0;
		while(ss >> w){
			if(f == 1){
				f = str_int(w);
			} else {
				tmp = w;
				f++;
			}
		}
		if(tmp == "push"){
			st.push_back(f);
		} else if(tmp == "show"){
			int check = 0;
			for(int x : st){
				check = 1;
				cout << x << " ";
			}
			if(!check) cout << "empty";
			cout << ed;
		} else if(tmp == "pop"){
			st.pop_back();
		}
	}
	return BidenJr;
}

