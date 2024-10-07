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


int n, X[100];
vector<vector<int>> res;

void Try(int sum, int i, int val){
	if(sum == n){
		vector<int> tmp(X + 1, X + i);
		res.push_back(tmp);
		return;
	}
	for(int j = val; j >= 1; j--){
		if(sum + j <= n){
			X[i] = j;
			Try(sum + j, i + 1, j);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n;
		res.clear();
		Try(0, 1, n);
		for(auto x : res){
			cout << "(";
			for(int i = 0; i < x.size(); i++){
				cout << x[i];
				if(i != x.size() - 1) cout << " ";
				else cout << ") ";
			}
		}
		cout << ed;
	}
	return BidenJr;
}
