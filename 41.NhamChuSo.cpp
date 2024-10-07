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

ll minsum(string n, string m){
	for(int i = 0; i < n.size(); i++) if(n[i] == '6') n[i] = '5';
	for(int i = 0; i < m.size(); i++) if(m[i] == '6') m[i] = '5';
	return str_int(n) + str_int(m);
}

ll maxsum(string n, string m){
	for(int i = 0; i < n.size(); i++) if(n[i] == '5') n[i] = '6';
	for(int i = 0; i < m.size(); i++) if(m[i] == '5') m[i] = '6';
	return str_int(n) + str_int(m);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string n, m;
	cin >> n >> m;
	cout << minsum(n, m) << " " << maxsum(n, m);
	return BidenJr;
}

