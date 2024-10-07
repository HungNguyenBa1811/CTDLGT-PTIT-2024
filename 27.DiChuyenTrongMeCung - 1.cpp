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

int a[100][100];
int n, ok;
string s = "";

void Try(int i, int j){
	if(i == n && j == n){
		ok = 1;
		cout << s << " ";
	}
	// gan nuoc di tiep theo khi o (i j)
	if(i + 1 <= n && a[i + 1][j] == 1){
		s += "D";
		a[i + 1][j] = 0; // danh dau la di roi
		Try(i + 1, j);
		s.pop_back();
		a[i + 1][j] = 1;
	}
	if(j + 1 <= n && a[i][j + 1] == 1){
		s += "R";
		a[i][j + 1] = 0;
		Try(i, j + 1);
		s.pop_back();
		a[i][j + 1] = 1;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				cin >> a[i][j];
		ok = 0;
		if(a[1][1]) Try(1, 1);
		if(!ok) cout << -1;
		cout << ed;
	}
	return BidenJr;
}
