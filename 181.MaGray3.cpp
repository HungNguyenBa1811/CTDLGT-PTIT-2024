#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Ma gray:
// bit 1: ma gray = ma nhi phan
// bit i (i > 1): ma gray = ma nhi phan i XOR ma nhi phan i - 1;
// XOR: 1 0 => 1 <= 0 1 ||| 0 0 => 0 <= 1 1
void solve(string s){
	cout << s[0];
	for(int i = 1; i < s.size(); i++){
		if(s[i] == s[i - 1]) cout << 0;
		else cout << 1;
	}
	cout << endl;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		solve(s);
	}
	// Biden
	return 0;
}

