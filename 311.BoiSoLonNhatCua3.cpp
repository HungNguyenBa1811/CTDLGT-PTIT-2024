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

int solve(int a[], int n){
	sort(a, a + n);
	queue<int> q, q1, q2;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
		if(a[i] % 3 == 1) q1.push(a[i]);
		else if(a[i] % 3 == 2) q2.push(a[i]);
		else q.push(a[i]);
	}
	if(sum % 3 == 1){
	    if(!q1.empty()) q1.pop();
	    else {
            if(!q2.empty()) q2.pop();
            else return -1;
            if(!q2.empty()) q2.pop();
            else return -1;
		}
	}
	if(sum % 3 == 2){
	    if(!q2.empty()) q2.pop();
	    else {
            if(!q1.empty()) q1.pop();
            else return -1;
            if(!q1.empty()) q1.pop();
            else return -1;
	    }
	}
	vector<int> ans;
	while(!q.empty()){
	    ans.push_back(q.front());
	    q.pop();
	}
	while(!q1.empty()){
	    ans.push_back(q1.front());
	    q1.pop();
	}
	while(!q2.empty()){
	    ans.push_back(q2.front());
	    q2.pop();
	}
	if(ans.empty()) return -1;
	sort(ans.begin(), ans.end(), greater<int>());
	for(int x : ans) cout << x;
	cout << ed;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		if(solve(a, n) == -1) cout << -1 << ed;
	}
	return BidenJr;
}
