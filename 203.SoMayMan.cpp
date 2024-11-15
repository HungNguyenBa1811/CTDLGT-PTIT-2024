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

string solve(int n){
	int ans_x = 1e9, ans_y = 1e9;
	for(int y = 0; y <= n / 7; y++){
		if((n - 7 * y) % 4 == 0){
		  int x = (n - 7 * y) / 4;
			if(ans_x + ans_y > x + y || (ans_x + ans_y == x + y && ans_x > x)){
				ans_x = x;
				ans_y = y;
			}
		}
	}
	if(ans_x == 1e9 && ans_y == 1e9) return "-1";
	else return string(ans_x, '4') + string(ans_y, '7');
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << solve(n) << ed;
	}
	return BidenJr;
}
