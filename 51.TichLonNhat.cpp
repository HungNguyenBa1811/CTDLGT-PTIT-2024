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
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int max1 = a[0] * a[1];
    int max2 = a[n - 1] * a[n - 2];
    int max3 = a[0] * a[1] * a[n - 1];
	int max4 = a[n - 1] * a[n - 2] * a[n - 3];
    cout << max({max1, max2, max3, max4}) << ed;
	return BidenJr;
}

