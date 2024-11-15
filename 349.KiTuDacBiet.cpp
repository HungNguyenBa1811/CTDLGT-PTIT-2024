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
ll n, len;

// COW -> COW/WCO -> COWWCO/OCOWWC
char search(ll n, ll k){
	// n = pos
	// k = len
	if(n <= s.size()) return s[n - 1];
	if(n <= k / 2){
		// search nua trai
		return search(n, k / 2);
	} else {
		// search nua phai
		ll tmp = n - k / 2;
		if(tmp == 1) return search(k / 2, k / 2);
		else return search(tmp - 1, k / 2);
	}
}

void inp(){
	cin >> s >> n;
	len = s.size();
	while(len < n) len *= 2;
	cout << search(n, len) << ed;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		inp();
	}
	return BidenJr;
}
