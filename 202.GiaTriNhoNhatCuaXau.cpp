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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		unordered_map<char, int> mp;
		priority_queue<int> pq;
		string s; cin >> s;
		for(char x : s) mp[x]++;
		for(auto el : mp) pq.push(el.second);
		while(n--){
			int tmp = pq.top() - 1;
			pq.pop();
			pq.push(tmp);
		}
		ll ans = 0;
		while(!pq.empty()){
			ans += pq.top() * pq.top();
			pq.pop();
		}
		cout << ans << ed;
	}
	return BidenJr;
}
