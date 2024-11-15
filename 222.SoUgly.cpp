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

vector<ll> ugly;
void sieve(){
	queue<ll> q;
	set<ll> se;
	q.push(1);
	while(!q.empty()){
		ll x = q.front(); q.pop();
		ugly.push_back(x);  
		if(x > 1e18) break;
		if(!se.count(x * 2)){
			q.push(x * 2);
			se.insert(x * 2);
		}
		if(!se.count(x * 3)){
			q.push(x * 3);
			se.insert(x * 3);
		}
		if(!se.count(x * 5)){
			q.push(x * 5);
			se.insert(x * 5);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sieve();
	sort(begin(ugly), end(ugly));
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << ugly[n - 1] << ed;
	}
	return BidenJr;
}
