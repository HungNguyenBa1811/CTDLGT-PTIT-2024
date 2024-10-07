#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ed "\n"
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define BidenJr 0
int x_4axis[] = {1, 0, 0, -1};
int y_4axis[] = {0, -1, 1, 0};
int x_8axis[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y_8axis[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int MOD = 1e9 + 7;

int a[10][10];
int n, ok;
string s;
string path = "DLRU";

void Try(int i, int j){
	if(i == n && j == n){
		cout << s << " ";
		ok = 1;
		return;
	}
	a[i][j] = 0;
	for(int k = 0; k < 4; k++){
		int i1 = i + x_4axis[k];
		int j1 = j + y_4axis[k];
		if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1]){
			s += path[k];
			a[i1][j1] = 0;
			Try(i1, j1);
			s.pop_back();			
			a[i1][j1] = 1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		s = "";
		cin >> n;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				cin >> a[i][j];
		ok = 0;
		s = "";
		if(a[1][1] && a[n][n]){
			Try(1, 1);
		}
		if(!ok) cout << -1;
		cout << ed;
	}
	return BidenJr;
}
