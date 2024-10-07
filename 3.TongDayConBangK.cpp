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

int a[1001];
int n, k;
vector<int> v;
vector<vector<int>> res;

void Try(int i, int sum){
  if(i > n) return;
  if(sum > k) return;
	if(sum == k){
		res.push_back(v);
		return;
	}
	Try(i + 1, sum);	
	v.push_back(a[i]);
	Try(i + 1, sum + a[i]);
	v.pop_back();
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	Try(0, 0);
	for(vector<int> s : res){
		for(int x : s) cout << x << " ";
		cout << ed;
	}
	cout << res.size();
	return BidenJr;
}

