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

string s;

void Try(int j, int k){
	if(k == 0 || j == s.size()) return;
	int mval = s[j], midx = j;
	for(int i = j + 1; i < s.size(); i++){
		if(mval <= s[i]) mval = s[i], midx = i;
	}
	if(midx == j || mval == s[j]){
		Try(j + 1, k);
		return;
	}
	swap(s[j], s[midx]);
	Try(j + 1, k - 1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int k;
		cin >> k >> s;
		Try(0, k);
		cout << s << ed;
	}
	return BidenJr;
}
