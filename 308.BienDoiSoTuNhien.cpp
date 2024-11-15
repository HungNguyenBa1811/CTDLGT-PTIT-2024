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

void BFS(int n){
	queue<pair<int, int>> q;
	map<int, int> visited;
	q.push({n, 0});
	while(!q.empty()){
		pair<int, int> tmp = q.front();
		q.pop();
		if(tmp.first == 2){
			cout << tmp.second + 1 << ed;
			return;
		}
		for(int i = 2; i <= sqrt(tmp.first); i++){
			if(tmp.first % i == 0 && !visited[tmp.first / i]){
				visited[tmp.first / i] = 1;
				q.push({tmp.first / i, tmp.second + 1});
			}
		}
		q.push({tmp.first - 1, tmp.second + 1});
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		BFS(n);
	}
	return BidenJr;
}

