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

int solve(int s, int t){
	queue<pair<int, int>> q;
	map<int, int> check;
	q.push({s, 0});
	while(q.front().first != t){
		int tmp = q.front().first;
		int step = q.front().second;
		check[tmp] = 1;
		q.pop();
		if(tmp < t && !check[tmp * 2]){
			q.push({tmp * 2, step + 1});
		}
		if(!check[tmp - 1]){
			q.push({tmp - 1, step + 1});
		}
	}
	return q.front().second;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--){
		int s, t;
		cin >> s >> t;
		cout << solve(s, t) << ed;
	}
	return BidenJr;
}
