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

int check(int x){
	return x % 2;
}

vector<int> v;
vector<vector<int>> res;
int a[20], n, sum = 0;

void Try(int pos){
	for(int i = pos; i < n; i++){
		sum += a[i];
		v.push_back(a[i]);
		if(check(sum)) res.push_back(v);
		if(i + 1 < n) Try(i + 1);
		v.pop_back();
		sum -= a[i];
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n, greater<int>());
		Try(0);
		sort(res.begin(), res.end());
		for(vector<int> x : res){
			for(int y : x){
				cout << y << " ";
			}
			cout << ed;
		}
		res.clear();
	}
	return BidenJr;
}
