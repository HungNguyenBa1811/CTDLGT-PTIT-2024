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
	deque<int> dq;
	while(t--){
		string s; cin >> s;
		if(s == "PUSHFRONT"){
			int n; cin >> n;
			dq.push_front(n);
		} else if(s == "PUSHBACK"){
			int n; cin >> n;
			dq.push_back(n);
		} else if(s == "POPFRONT"){
			if(!dq.empty()) dq.pop_front();
		} else if(s == "POPBACK"){
			if(!dq.empty()) dq.pop_back();
		} else if(s == "PRINTFRONT"){
			if(!dq.empty()) cout << dq.front() << ed;
			else cout << "NONE" << ed;
		} else if(s == "PRINTBACK"){
			if(!dq.empty()) cout << dq.back() << ed;
			else cout << "NONE" << ed;
		}
	}
	return BidenJr;
}

