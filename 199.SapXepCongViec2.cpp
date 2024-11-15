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

struct work{
	int jobID;
	int deadline;
	int profit;
	bool operator < (work a){
		return profit < a.profit;
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		work a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i].jobID >> a[i].deadline >> a[i].profit;
		sort(a, a + n);
		int cnt = 0, ans = 0;
		int visited[1001] = {0};
		for(int i = n - 1; i >= 0; i--){
			for(int j = a[i].deadline; j >= 1; j--){
				if(!visited[j]){
					cnt++;
					ans += a[i].profit;
					visited[j] = 1;
					break;
				}
			}
		}
		cout << cnt << " " << ans << ed;
	}
	return BidenJr;
}
