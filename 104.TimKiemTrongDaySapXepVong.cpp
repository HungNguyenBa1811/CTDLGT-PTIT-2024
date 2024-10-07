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

int binSearch(vector<int> a, int n, int x) {
    int l = 1, r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if(a[mid] == x) return mid;
        else if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n, k, f = 1;
		int ans = 0;
		cin >> n >> k;
		vector<int> a;
		vector<int> b;
		a.push_back(-1);
		b.push_back(-1);
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			if(i != 0 && x < a[i - 1]) f = 0;
			if(f) a.push_back(x);
			else b.push_back(x);
		}
		ans = binSearch(a, a.size(), k);
		if(ans == -1) ans = a.size() - 1 + binSearch(b, b.size(), k);
		cout << ans << ed;
	}
	return BidenJr;
}

