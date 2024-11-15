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
	int n;
	string s;
	cin >> n >> s;
    vector<int> a(n + 5);
    int x = 0, t = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'X'){
            a[i + 1] = 0;
            x++;
        } else if(s[i] == 'T'){
            a[i + 1] = 1;
            t++;
        } else a[i + 1] = 2;
    }
    int ans = 0;
    int cnt_x = 0, cnt_t = 0, cnt_d = 0;
    for(int i = 1; i <= x; i++) {
        if(a[i] == 0) cnt_x++;
        else if (a[i] == 1) cnt_t++;
        else cnt_d++;
    }
    ans += x - cnt_x;
    for(int i = x + 1; i <= n; i++){
        if(cnt_t == 0 && cnt_d == 0) break;
        if(cnt_t > 0 && a[i] == 0){ // Swap 'X' to 'T'
            a[i] = 1;
            cnt_t--;
        } else if(cnt_d > 0 && a[i] == 0){ // Swap 'X' to 'D'
            a[i] = 2;
            cnt_d--;
        }
    }
    for(int i = x + 1; i <= x + t; i++){
        if(a[i] == 1) cnt_t++;
    }
    ans += t - cnt_t;
    cout << ans;
	return BidenJr;
}
