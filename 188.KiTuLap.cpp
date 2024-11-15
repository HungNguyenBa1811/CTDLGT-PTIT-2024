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

int cnt_dup(string s1, string s2){
	int i = 0, j = 0, cnt = 0;
	while(i < s1.size() && j < s2.size()){
		if(s1[i] == s2[j]) cnt++, i++, j++;
		else if(s1[i] < s2[j]) i++;
		else j++;
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<string> a(n);
	int X[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) X[i] = i;
	int dup[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dup[i][j] = dup[j][i] = cnt_dup(a[i], a[j]);
		}
	}
	int ans = 1e9;
	do {
		int cnt = 0;
		for(int i = 1; i < n; i++) cnt += dup[X[i - 1]][X[i]];
		ans = min(ans, cnt);
	} while (next_permutation(X, X + n));
	cout << ans;
	return BidenJr;
}
