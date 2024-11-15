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

ll cnt;

void merge(ll a[], int l, int r, int m){
	vector<ll> x(a + l, a + m + 1);
	vector<ll> y(a + m + 1, a + r + 1);
	int i = 0, j = 0, k = l;
	while(i < x.size() && j < y.size()){
		if(x[i] > y[j]){
			a[k++] = y[j++];
			cnt += x.size() - i;
		} else a[k++] = x[i++];
	}
	while(i < x.size()) a[k++] = x[i++];
	while(i < y.size()) a[k++] = y[j++];
}

void mergeSort(ll a[], int l, int r){
	if(l >= r) return;
	int mid = l + (r - l) / 2;
	mergeSort(a, l, mid);
	mergeSort(a, mid + 1, r);
	merge(a, l, r, mid);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		ll a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		cnt = 0;
		mergeSort(a, 0, n - 1);
		cout << cnt << ed;
	}
	return BidenJr;
}

