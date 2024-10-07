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

void solve(vector<int>& arr, int k){
    vector<int> ans;
    priority_queue<pair<int, int>> heap;
    for(int i = 0; i < k; i++) heap.push({ arr[i], i });
    ans.push_back(heap.top().first);
    for(int i = k; i < arr.size(); i++){
        heap.push({ arr[i], i });
        while(heap.top().second <= i - k) heap.pop();
        ans.push_back(heap.top().first);
    }
    for(auto i : ans) cout << i << " ";
    cout << ed;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a;
		vector<int> v;
		for(int i = 0; i < n; i++){
			cin >> a;
			v.push_back(a);
		}
		solve(v, k);
	}
	return BidenJr;
}
