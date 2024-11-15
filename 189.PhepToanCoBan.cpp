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

string s, x;
char oprt[] = {'+', '-', '*', '/'};
int ok;

int check(){
	int a = (x[0] - '0') * 10 + x[1] - '0';
	int b = (x[5] - '0') * 10 + x[6] - '0';
	int c = (x[10] - '0') * 10 + x[11] - '0';
	
	if(x[3] == oprt[0]) return a + b == c;
	if(x[3] == oprt[1]) return a - b == c;
	if(x[3] == oprt[2]) return a * b == c;
	return a / b == c;
}

void Try(int i){
	if(ok) return;
	if(i == s.size()){
		if(check()){
			ok = 1;
			cout << x << ed;
		}
		return;
	}
	if(s[i] != '?') Try(i + 1);
	else {
		if(i == 3){
			for(int j = 0; j < 4; j++){
				x[i] = oprt[j];
				Try(i + 1);
			}
		} else {
			for(int j = 0; j <= 9; j++){
				if(j == 0 && (i == 0 || i == 5 || i == 10)) continue;
				x[i] = '0' + j;
				Try(i + 1);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; cin.ignore();
	while(t--){
		getline(cin, s);
		x = s;
		ok = 0;
		Try(0);
		if(!ok) cout << "WRONG PROBLEM!" << ed;
	}
	return BidenJr;
}

