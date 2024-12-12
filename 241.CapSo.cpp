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

int f[100005];

int solve(int x){
	int res = 0;
	while(x < 100005){
		res += f[x];
		x += x & -x;
	}
	return res;
}

void upd(int x){
	while(x > 0){
		f[x]++;
		x -= x & -x;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n + 5];
	for(int i = 1; i <= n; i++) cin >> a[i];
	int res = 0;
	vector<int> v;
	for(int i = 1; i <= n; i++){
		if(a[i] % 2 == 0){
			res += solve(a[i] + 1);
			v.push_back(a[i]);
		} else {
			for(int &i : v) upd(i);
			v.clear();
		}
	}
	cout << res << ed;
	return BidenJr;
}

