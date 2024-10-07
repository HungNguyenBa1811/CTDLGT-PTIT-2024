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
		ll n; cin >> n;
		queue<string> q;
		set<ll> se;
		string s;
		q.push("9");
		while(!q.empty()){
			s = q.front(); q.pop();
			ll sex = stoll(s) % n;
			if(sex == 0){
				cout << s << ed;
				break;
			}
			if(se.find(sex) == se.end()){
				se.insert(sex);
				q.push(s + "0");
				q.push(s + "9");				
			}
		}
	}
	return BidenJr;
}
