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

vector<int> snt;

int checknt(int n){
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0) return 0;
	}
	return n > 1;
}

void sieve(){
	for(int i = 2; i <= 200; i++){
		if(checknt(i)) snt.push_back(i);
	}
}

int n, p, s, X[15];
vector<string> ans;

void Try(int i, int prev, int sum){
	for(int j = prev + 1; j < snt.size(); j++){
		if(snt[j] <= p) continue;
		if(sum + snt[j] > s) continue;
		
		X[i] = snt[j];
		if(i == n && sum + snt[j] == s){
			string tmp = "";
			for(int i = 1; i <= n; i++){
				tmp += to_string(X[i]) + " ";
			}
			ans.push_back(tmp);
		}
		if(i < n) Try(i + 1, j, sum + snt[j]);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	sieve();
	while(t--){
		cin >> n >> p >> s;
		Try(1, 0, 0);
		sort(ans.begin(), ans.end());
		cout << ans.size() << ed;
		for(string x : ans) cout << x << ed;
		ans.clear();
	}
	return BidenJr;
}

