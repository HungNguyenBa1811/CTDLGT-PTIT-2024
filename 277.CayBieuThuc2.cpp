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

string tree[1001];

int calc(int i){
	if(tree[i] == "+")
		return calc(i * 2 + 1) + calc(i * 2 + 2);
	else if(tree[i] == "-")
		return calc(i * 2 + 1) - calc(i * 2 + 2);
	else if(tree[i] == "*")
		return calc(i * 2 + 1) * calc(i * 2 + 2);
	else if(tree[i] == "/")
		return calc(i * 2 + 1) / calc(i * 2 + 2);
	else
		return stoi(tree[i]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i = 0; i < n; i++) cin >> tree[i];
		cout << calc(0) << ed;
	}
	return BidenJr;
}
