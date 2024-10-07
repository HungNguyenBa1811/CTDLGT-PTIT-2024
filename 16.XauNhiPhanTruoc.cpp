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

int n, ok;
string s;

void sinh(){
	int i = n;
	while(i >= 1 && s[i] == '0'){
		s[i] = (char) '1';
		--i;
	}
	if(i == 0) ok = 0;
	else s[i] = (char) '0';
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> s;
		ok = 1;
		n = s.size();
		s = 'u' + s;
		sinh();
		if(!ok){
			for(int i = 0; i < n; i++) cout << "1";
			cout << ed;
		} else {
			for(char x : s) if(x != 'u') cout << x;
			cout << ed;
		}
	}
	return BidenJr;
}

