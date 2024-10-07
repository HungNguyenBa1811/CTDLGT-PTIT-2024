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

string s;
vector<string> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int a[n], ans[n];
    for(int i = 0; i < n; i++) cin >> a[i];
	int pos = 1;
    ans[0] = a[0];
    s = "";
    s += "Buoc 0: " + to_string(ans[0]);
    v.push_back(s);
    for(int i = 1; i < n; i++){
        s = "";
        s += "Buoc " + to_string(pos) + ": ";
        ans[pos++] = a[i];
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && ans[j] > key){
            ans[j + 1] = ans[j];
            j--;
        }
        ans[j + 1] = key;
        for(int k = 0; k < pos; k++) s += to_string(ans[k]) + " ";
        v.push_back(s);
    }
	reverse(v.begin(), v.end());
	for(string x : v) cout << x << ed;
	v.clear();
	return BidenJr;
}

