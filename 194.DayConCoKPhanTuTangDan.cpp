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

vector<int> a;
int X[101], n, k;
bool ok;

void ktao(){
	for(int i = 1; i <= k; i++){
		X[i] = i;
	}
}

void sinh(){
	int i = k;
	while(i >= 1 && X[i] == n - k + i){
		--i;
	}
	if(i == 0) ok = false;
	else {
		X[i]++;
		for(int j = i + 1; j <= k; j++){
			X[j] = X[j - 1] + 1;
		}
	}
}

void cpy(int x){
	a.push_back(x);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		set<int> se;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			se.insert(x);
		}
		n = se.size();
		for_each(se.begin(), se.end(), cpy);
		ok = true;
		ktao();
		while(ok){
			for(int i = 1; i <= k; i++){
				cout << a[X[i] - 1] << " ";
			}
			cout << ed;
			sinh();
		}
		cout << ed;
		a.clear();
	}
	return BidenJr;
}

