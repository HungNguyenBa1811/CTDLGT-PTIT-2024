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

string ans;
vector<string> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int cnt = 0;
		for(int i = 0; i < n - 1; i++){
		    int f = 0;
		    for(int j = 0; j < n - i - 1; j++){
	    	    if(a[j] > a[j + 1]){
	    	        swap(a[j], a[j + 1]);
	    	        f = 1;
	    	    }
		    }
		    if(f){
	            cnt++;
	            ans = "";
	            ans += "Buoc " + to_string(cnt) + ": ";
	            for(int k = 0; k < n; k++) ans += to_string(a[k]) + " ";
	            v.push_back(ans);
		    }
		}
		reverse(v.begin(), v.end());
		for(string x : v) cout << x << ed;
		v.clear();	
	}
	return BidenJr;
}

