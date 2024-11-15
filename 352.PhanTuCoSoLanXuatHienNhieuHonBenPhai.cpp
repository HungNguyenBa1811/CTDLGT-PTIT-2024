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
	    int n; cin >> n;
	    vector<int> a(n);
	    map<int, int> mp;
	    for(int i = 0; i < n; i++){
	        cin >> a[i];
	        mp[a[i]]++;
	    }
	    vector<int> res(n);
	    stack<int> st;
	    for (int i = n - 1; i >= 0; i--) {
	        while(!st.empty() && mp[st.top()] <= mp[a[i]])
	            st.pop();
	        if(st.empty()) res[i] = -1;
	        else res[i] = st.top();
	        st.push(a[i]);
	    }
	    for(int i = 0; i < n; i++){
	        cout << res[i] << " ";
	    }
	    cout << ed;
	}
	return BidenJr;
}

