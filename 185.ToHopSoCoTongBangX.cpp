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

vector<int> x;
int a[1001];
int n, k, f;

void printx(){
	cout << "[";
	for(int i = 0; i < x.size() - 1; i++) cout << x[i] << " ";
	cout << x[x.size() - 1] << "]";
}

void Try(int j, int sum){
	if(sum > k || j > n) return;
	if(sum == k){
	    printx();
	    f = 1;
	    return;
	}
	if(a[j] != 0){
	    x.push_back(a[j]);
	    Try(j, sum + a[j]);
	    x.pop_back();
	}
	for(int i = j + 1; i <= n; i++){
	    x.push_back(a[i]);
	    Try(i, sum + a[i]);
	    x.pop_back();    
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <= n; i++) cin >> a[i];
		a[0] = 0;
		f = 0;
		Try(0, 0);
		if(!f) cout << -1;
		cout << ed;
	}
	return BidenJr;
}
