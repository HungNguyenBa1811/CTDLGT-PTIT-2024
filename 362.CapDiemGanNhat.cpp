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

struct Point {
    double x, y;
};
bool cmp_x(const Point &a, const Point &b) {
    return a.x < b.x;
}
bool cmp_y(const Point &a, const Point &b) {
    return a.y < b.y;
}

Point a[100005];
double ans;

void upd_ans(const Point &a, const Point &b) {
    double dist = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    if (dist < ans) ans = dist;
}

void find(int l, int r) {
    if (r <= l) return;
    if (r == l + 1) {
        upd_ans(a[l], a[r]);
        if (!cmp_y(a[l], a[r])) swap(a[l], a[r]);
        return;
    }
    int m = (l + r) / 2;
    double mid_x = a[m].x;
    find(l, m);
    find(m + 1, r);

    static Point t[100005];
    merge(a + l, a + m + 1, a + m + 1, a + r + 1, t, cmp_y);
    copy(t, t + r - l + 1, a + l);
    // |x_i - midx| < ans,
    int tmp = 0;
    for(int i = l; i <= r; i++){
		if (abs(a[i].x - mid_x) < ans){
	        for (int j = tmp - 1; j >= 0 && t[j].y > a[i].y - ans; j--){
	        	upd_ans(a[i], t[j]);
			}
	        t[tmp++] = a[i];
	    }    	
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
	    int n; cin >> n;
	    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
	    ans = 1e18;
	    sort(a, a + n, cmp_x);
	    find(0, n - 1);
        cout << fixed << setprecision(6) << ans << ed;
    }
    return BidenJr;
}
