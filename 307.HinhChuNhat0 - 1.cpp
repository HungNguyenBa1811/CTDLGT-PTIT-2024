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

ll solve(vector<int> a){
    int n = a.size();
    vector<int> l(n), r(n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if(!st.empty()) l[i] = st.top() + 1;
        else l[i] = 0;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if(!st.empty()) r[i] = st.top() - 1;
        else r[i] = n - 1;
        st.push(i);
    }
    ll res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, 1ll * a[i] * (r[i] - l[i] + 1));
    }
    return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    vector<vector<int>> a(n, vector<int> (m));
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            cin >> a[i][j];
	            if(i > 0 && a[i][j] == 1 && a[i - 1][j] > 0)
	                a[i][j] = a[i - 1][j] + 1;
	        }
	    }
	    ll res = 0;
	    for(int i = 0; i < n; i++)
	        res = max(res, solve(a[i]));
	    cout << res << ed;
	}
	return BidenJr;
}

