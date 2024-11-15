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

typedef struct Item {
	int wgh, val;
} Item;

// Greedy with ratio comparision
bool cmp(Item a, Item b){
    double r1 = 1.0 * a.val / (1.0 * a.wgh);
    double r2 = 1.0 * b.val / (1.0 * b.wgh);
    return r1 > r2;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n, w;
		cin >> n >> w;
		Item a[n];
		for(int i = 0; i < n; i++) cin >> a[i].val >> a[i].wgh;
		sort(a, a + n, cmp);
		double ans = 0;
		for(int i = 0; i < n; i++){
			if(a[i].wgh <= w){
				w -= a[i].wgh;
				ans += a[i].val;
			} else {
				ans += a[i].val * (1.0 * w / (1.0 * a[i].wgh));
				break;
			}
		}
		cout << fixed << setprecision(2);
		cout << ans << ed;
	}
	return BidenJr;
}
