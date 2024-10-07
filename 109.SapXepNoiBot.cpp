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
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int cnt = 1;
	for(int i = 0; i < n - 1; i++){
	    int f = 0;
	    for(int j = 0; j < n - i - 1; j++){
    	    if(a[j] > a[j + 1]){
    	        swap(a[j], a[j + 1]);
    	        f = 1;
    	    }
	    }
	    if(f){
    	    cout << "Buoc " << cnt << ": ";
			cnt++;
        	for(int j = 0; j < n; j++) cout << a[j] << " ";
        	cout << ed;
	    }
	}
	return BidenJr;
}

