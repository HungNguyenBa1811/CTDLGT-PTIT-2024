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

bool check(string s){
	int cnt1 = 0, cnt2 = 0;
	for(char x : s){
		if(x == '+' || x == '-') cnt1++; 
		if(x == '(') cnt2++;
	}
	return cnt1 != cnt2;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		if(check(s)) cout << "Yes" << ed;
		else cout << "No" << ed;
	}
	return BidenJr;
}
