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

int check(int d, string s){
	map<char, int> dem;
	for(char x : s) dem[x]++;
	int k = 0;
	for(auto x : dem) k = fmax(k, x.second);
	int n = s.size();
	if(k - (n - k)/(d - 1) <= 1) return 1; 
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int d; cin >> d;
		string s;
		cin >> s;
		cout << check(d, s) << ed;
	}
	return 0;
}

