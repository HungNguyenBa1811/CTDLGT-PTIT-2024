#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Thuat toan chuyen tu ma gray => ma nhi phan:
// - bit 1: ma gray = ma nhi phan
// - bit i:
// + bit i = 0: bit i nhi phan = bit i - 1 nhi phan
// + bit i = 1: bit i  nhi phan = lat(bit i - 1) nhi phan

void solve(string s){
	string res = "";
	res += s[0];
	for(int i = 1; i < s.size(); i++){
		if(s[i] == '1'){
			if(res[i - 1] == '0') res += '1';
			else res += '0';
		}
		else res += res[i - 1];
	}
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		string s;
		cin >> s;
		solve(s);
	}
	// Biden
	return 0;
}

