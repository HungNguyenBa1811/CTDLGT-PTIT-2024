#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ed "\n"
#define use(x) freopen(x ".inp", "r", stdin); freopen(x ".out", "w", stdout);
#define BidenJr 0
int x_4axis[] = {-1, 0, 0, 1};
int y_4axis[] = {0, -1, 1, 0};
int x_8axis[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y_8axis[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int MOD = 1e9 + 7;

pair<int, int> a;
set<pair<int, int>> s[100000];
int n, ans = 0;

bool check(pair<int, int> a, pair<int, int> b) {
    return ((a.first < b.first) && (a.second < b.second));
}

int kt(set<pair<int, int>> &st){
    for (auto i = st.begin(); i != st.end(); i++) {
        if (check(*i, a)) return 1;
        else if (i->first >= a.first) break; // Early exit for efficiency.
    }
    return 0;
}

int bin_search(int l, int r){
    while (l < r) {
        int mid = (l + r) / 2;
        if (kt(s[mid])) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a.first >> a.second;
        int pos = bin_search(0, n);
        if (pos < n) {
            auto k = s[pos].insert(a).first;
            k++;
            while (k != s[pos].end()) {
                if (check(a, *k)) {
                    auto to_erase = k; 
                    k++;
                    s[pos].erase(to_erase);
                    break;
                }
            }
        }
    }
    while (ans < n && !s[ans].empty()) ans++;
    cout << ans << ed;
    return BidenJr;
}

