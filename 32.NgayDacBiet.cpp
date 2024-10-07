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

int n, ok, X[100];
string s = "";
vector<int> v;
vector<vector<int>> ngay;
vector<vector<int>> nam;
vector<string> res;

void ktao(int id){
	ok = 1;
	for(int i = 1; i <= n; i++) X[i] = 0;
	X[id] = 2;
}

void sinh(){
	int i = n;
	while(i > 0 && X[i] == 2){
		X[i] = 0;
		i--;
	}
	if(i == 0) ok = 0;
	else X[i] = 2;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	n = 2;
	ktao(2);
	while(ok){
		for(int i = 1; i <= n; i++) v.push_back(X[i]);
		ngay.push_back(v);
		v.clear();
		sinh();
	}
	n = 4;
	ktao(1);
	while(ok){
		for(int i = 1; i <= n; i++) v.push_back(X[i]);
		nam.push_back(v);
		v.clear();
		sinh();
	}
	for(vector<int> dd : ngay){
		for(vector<int> yyyy : nam){
			s = "";
			for(int d : dd) s += to_string(d);
			s += "/02/";
			for(int y : yyyy) s += to_string(y);
			res.push_back(s);
		}
	}
	sort(res.begin(), res.end());
	for(string w : res) cout << w << ed;
	return BidenJr;
}

