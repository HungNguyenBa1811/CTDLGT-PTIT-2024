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
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s = "";
		string s1 = "";
		string s2 = "";
		for(int i = 0; i < n; i++){
			char x; cin >> x;
			s += x;
		}
		sort(s.begin(), s.end());
		for(int i = 0; i < n; i++){
			if(i % 2) s1 += s[i];
			else s2 += s[i];
		}
		cout << str_int(s1) + str_int(s2) << ed;
	}
	return BidenJr;
}

