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
	int check, cnt = 0;
	for(int i = 0; i < n; i++){
	    check = 0;
	    for(int j = i + 1; j < n; j++){
    	    if(a[i] > a[j]){
    	        swap(a[i], a[j]);
    	        check = 1;
    	    }
	    }
	    if(check){
            cnt++;
            cout << "Buoc " << cnt << ": ";
            for(int k = 0; k < n; k++) cout << a[k] << " ";
            cout << ed;
	    }
	}
	return BidenJr;
}

