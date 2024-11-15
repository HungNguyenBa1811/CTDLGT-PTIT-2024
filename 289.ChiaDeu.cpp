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

int n, k, ps[101], res, ans;

void Try(int i, int cnt){
	if(cnt == k && i == n){
		ans++;
		return;
	}
	for(int j = i + 1; j <= n; j++){
		if(ps[j] - ps[i] == res)
			Try(j, cnt + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	ps[0] = 0;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		ps[i] = ps[i - 1] + x;
	}
	if(ps[n] % k != 0) cout << "0";
	else {
		res = ps[n] / k;
		Try(0, 0);
		cout << ans;
	}
	return BidenJr;
}
