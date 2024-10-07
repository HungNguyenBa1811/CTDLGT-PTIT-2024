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

vector<int> v;
string min(int m, int s){
	if(s > m * 9 || m > 1 && s == 0) return "-1";
	v.resize(m, 0);
	string res = "";
	s -= 1;
	for(int i = m - 1; i >= 0; i--){
		if(s > 9){
			v[i] = 9;
			s -= 9;
		} else {
			v[i] = s;
			s = 0;
		}
	}
	v[0] += 1;
	for(int i = 0; i < m; i++){
		res += v[i] + '0';
	}
	v.clear();
	return res;
}

string max(int m, int s){
	if(s > m * 9 || m > 1 && s == 0) return "-1";
	v.resize(m, 0);
	string res = "";
	for(int i = 0; i < m; i++){
		if(s > 9){
			v[i] = 9;
			s -= 9;
		} else {
			v[i] = s;
			s = 0;
		}
	}
	for(int i = 0; i < m; i++){
		res += v[i] + '0';
	}
	v.clear();
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, s;
	cin >> m >> s;
	cout << min(m, s) << " " << max(m, s);
	return BidenJr;
}
