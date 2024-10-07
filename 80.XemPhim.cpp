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
	int c, n; cin >> c >> n;
	int dp[c + 1] = {0};
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	dp[0] = 1;
	// QHD Sum Subset: duyet nguoc, tim vi tri co do vat de them vao
	// 1 0 0 0 0 0 0 0 (0kg) (co so)
	// 1 0 0 1 0 0 0 0 (+3kg)
	// 1 0 1 1 0 1 0 0 (+2kg)
	// 1 0 1 1 0 1 1 0 (+6kg)
	for(int i = 0; i < n; i++){
		for(int j = c; j >= a[i]; j--){
			if(dp[j - a[i]]) dp[j] = 1; // Co do vat tai j - a[i] => add do vat a[i] vao => tong = j xuat hien
		}
	}
	for(int i = c; i >= 0; i--){
		if(dp[i]){
			cout << i << ed;
			return BidenJr;
		}
	}
	return BidenJr;
}

