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

int a[25], X[25], n;
vector<string> ans;

void Try(int i, int pos){
	for(int j = pos; j <= n; j++){
		if(X[i - 1] < a[j]){
			X[i] = a[j];
			if(i > 1){
				// luu lai
				string res = "";
				for(int k = 1; k <= i; k++) res += to_string(X[k]) + " ";
				ans.push_back(res);
			}
			Try(i + 1, j + 1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	Try(1, 1);
	sort(begin(ans), end(ans));
	for(string x : ans) cout << x << ed;
	return BidenJr;
}

