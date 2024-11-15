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

int BFS(string a, string b, unordered_set<string> v){
	queue<pair<string, int>> q;
	q.push({a, 1});
	while(!q.empty()){
		pair<string, int> tmp = q.front();
		q.pop();
		for(int i = 0; i < tmp.first.size(); i++){
			string x = tmp.first;
			for(char c = 'A'; c <= 'Z'; c++){
				x[i] = c;
				if(x == b) return tmp.second + 1;
				if(v.count(x)){
					q.push({x, tmp.second + 1});
					v.erase(x);
		    	}
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string a;
		string b;
		cin >> a >> b;
		unordered_set<string> v;
		for(int i = 0; i < n; i++){
			string x; cin >> x;
			v.insert(x);
		}
		cout << BFS(a, b, v) << ed;
	}
	return BidenJr;
}
