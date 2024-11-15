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

string catalan[101];

string add(string a, string b) {
    int n = a.size();
    int m = b.size();
    if (n < m) swap(a, b);
    n = a.size();
    m = b.size();
    string res = "";
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        if (i < m) tmp += b[m - i - 1] - '0';
        tmp += a[n - i - 1] - '0';
        res = char(tmp % 10 + '0') + res;
        tmp /= 10;
    }
    if (tmp) res = '1' + res;
    return res;
}

string mul(string a, string b){
	string res = "0";
	int n = a.size();
	int m = b.size();
	int du;
	for(int j = m - 1; j >= 0; j--){
		string tmp = string(m - j - 1, '0');
		du = 0;
		for(int i = n - 1; i >= 0; i--){
			int _tmp_ = (b[j] - '0') * (a[i] - '0') + du;
			tmp = to_string(_tmp_ % 10) + tmp;
			du = _tmp_ / 10;
		}
		if(du) tmp = to_string(du) + tmp;
		res = add(res, tmp);
	}
	return res;
}

void sieve(){
	catalan[0] = catalan[1] = "1";
	for(int i = 2; i <= 100; i++){
		for(int j = 0; j < i; j++){
			catalan[i] = add(catalan[i], mul(catalan[j], catalan[i - j - 1]));
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	sieve();
	while(t--){
		int n; cin >> n;
		cout << catalan[n] << ed;
	}
	return BidenJr;
}

