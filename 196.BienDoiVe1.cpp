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

int BFS(int n){
	queue<pair<int, int>> q;
	q.push({n, 0});
	while(1){
		int _n = q.front().first;
		int _cnt = q.front().second;
		q.pop();
		if(_n == 1) return _cnt;
		if(_n % 3 == 0) q.push({_n / 3, _cnt + 1});
		if(_n % 2 == 0) q.push({_n / 2, _cnt + 1});
		q.push({_n - 1, _cnt + 1});
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << BFS(n) << ed;
	}
	return BidenJr;
}

