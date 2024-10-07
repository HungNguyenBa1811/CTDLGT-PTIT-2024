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

string s = "";

int isvow(char x){
	if(x == 'A' || x == 'E') return 1;
	return 0;
}

int check(){
	for(int i = 0; i < s.size() - 2; i++){
		if(!isvow(s[i]) && isvow(s[i + 1]) && !isvow(s[i + 2])) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	char c; cin >> c;
	for(int i = 0; i <= c - 'A'; i++) s += (char) ('A' + i);
	do {
		if(check()) cout << s << ed;
	}
	while(next_permutation(s.begin(), s.end()));
	return BidenJr;
}

