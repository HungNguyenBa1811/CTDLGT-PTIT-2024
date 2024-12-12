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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
	    string a, b;
	    cin >> a >> b;
	    int n = a.size(), m = b.size();
	    int f[n + 1][m + 1] = {0};
	    for(int i = 0; i <= n; i++){
	        for(int j = 0; j <= m; j++){
	            if(i == 0) f[i][j] = j;
	            else if (j == 0) f[i][j] = i;
	            else if (a[i - 1] == b[j - 1]) f[i][j] = f[i - 1][j - 1];
	            else f[i][j] = min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
	        }
	    }
	    cout << f[n][m] << ed;
	}
	return BidenJr;
}

