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

deque<int> q;

void qsize(){
	cout << q.size() << ed; 
}

void qcheck(){
	if(q.empty()) cout << "YES" << ed;
	else cout << "NO" << ed;
}

void qpush(){
	int x; cin >> x;
	q.push_back(x);
}

void qpop(){
	if(q.empty()) return;
	q.pop_front();
}

void qtop(){
	if(!q.empty()){
		cout << q.front() << ed;
	} else cout << -1 << ed;
}

void qback(){
	if(!q.empty()){
		cout << q.back() << ed;
	} else cout << -1 << ed;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		while(n--){
			int k; cin >> k;
			switch(k){
				case 1:
					qsize();
					break;
				case 2:
					qcheck();
					break;
				case 3:
					qpush();
					break;
				case 4:
					qpop();
					break;
				case 5:
					qtop();
					break;
				case 6:
					qback();
					break;
			}
			
		}
		q.clear();
	}
	return BidenJr;
}

