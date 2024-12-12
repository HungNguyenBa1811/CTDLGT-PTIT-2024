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
        int n, ans = -1e9, s = -1e9;
        cin >> n;
        int a[4][n + 1], f[n + 1][11] = {}, d[] = {0, 1, 2, 4, 5, 8, 9, 10};
        for (int i = 0; i < 4; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        for(int j = 1; j <= n; j++){
            for(int k = 0; k < 8; k++){
                for(int i = 0; i < 4; i++){
                     if(d[k] & (1 << i))
                        f[j][d[k]] += a[i][j];               	
				}
                int x = -1e9;
                for(int i = 0; i < 8; i++){
                    if ((d[k] | d[i]) == (d[k] ^ d[i]))
                        x = max(x, f[j - 1][d[i]]);                	
				}
                f[j][d[k]] += x;
            }
        }
        for(int i = 0; i < 8; i++)
            s = max(f[n][d[i]], s);
        for(int i = 0; i < 4; i++)
            for(int j = 1; j <= n; j++)
                ans = max(ans, a[i][j]);
        if (ans < 0) cout << ans << ed;
        else cout << s << ed;
	}
	return BidenJr;
}

