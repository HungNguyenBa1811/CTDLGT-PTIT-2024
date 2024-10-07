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

void Try(int a[], int n){
	if(n < 1) return;
	int tmp[n];
	for(int i = 0; i < n - 1; i++) tmp[i] = a[i] + a[i + 1];
	cout << "[" << a[0];
	for(int i = 1; i < n; i++) cout << " " << a[i];
	cout << "] ";	
	Try(tmp, n - 1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		Try(a, n);
		cout << ed;
	}
	return BidenJr;
}

