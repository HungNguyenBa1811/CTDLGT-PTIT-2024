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

int n, k, ok;
int X[1001];

void ktao(){
	for(int i = 1; i <= k; i++) X[i] = i;
}

void sinh(){
	int i = k;
	while(i >= 1 && X[i] == n - k + i){
		--i;
	}
	if(i == 0) ok = 0;
	else {
		X[i]++;
		for(int j = i + 1; j <= k; j++){
			X[j] = X[j - 1] + 1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	set<string> se;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		se.insert(s);
	}
	n = se.size();
	vector<string> v;
	v.push_back("DangBeuCookieRunKingdom");
	for(string w : se){
		v.push_back(w);
	}
	ktao();
	ok = 1;
	while(ok){
		for(int i = 1; i <= k; i++){
			cout << v[X[i]] << " ";
		}
		cout << ed;
		sinh();
	}
	return BidenJr;
}

