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

int n, a[100];
bool ok;
vector<int> v;
vector<vector<int>> res;

void ktao(){
	for(int i = 1; i <= n; i++) a[i] = i;
}

void sinh(){
	int i = n - 1;
	while(i >= 1 && a[i] > a[i + 1]){
		--i;
	}
	if(i == 0) ok = false;
	else {
		// Tim j > i be nhat
		int j = n;
		while(a[i] > a[j]){
			--j;
		}
		swap(a[i], a[j]);
		reverse(a + i + 1, a + n + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		res.clear();
		cin >> n;
		ok = true;
		ktao();
		while(ok){
			v.clear();
			for(int i = 1; i <= n; i++){
				v.push_back(a[i]);
			}
			res.push_back(v);
			sinh();
		}
		reverse(res.begin(), res.end());
		for(vector<int> x : res){
			for(int y : x){
				cout << y;
			}
			cout << ' ';
		}
		cout << ed;
	}
	
	return BidenJr;
}

