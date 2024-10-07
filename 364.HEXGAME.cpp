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
int L[10] = {3, 0, 2, 7, 4, 1, 6, 8, 5, 9};
int R[10] = {0, 4, 1, 3, 8, 5, 2, 7, 9, 6};
int l[10] = {1, 5, 2, 0, 4, 8, 6, 3, 7, 9};
int r[10] = {0, 2, 6, 3, 1, 5, 9, 7, 4, 8};
const int MOD = 1e9 + 7;

struct Node {
    string config;
    int high;
    Node(string config, int high) {
        this->config = config;
        this->high = high;
    }
};

string S = "", T = "1238004765", le = "0012345678", ri = "0012345678";
map<string, int> xuoi;
map<string, int> nguoc;
bool stop = 0;

void rot(string s) {
    for (int i = 0; i < 10; ++i) {
        le[i] = s[L[i]];
        ri[i] = s[R[i]];
    }
}
void rot_reverse(string s) {
    for (int i = 0; i < 10; ++i) {
        le[i] = s[l[i]];
        ri[i] = s[r[i]];
    }
}
void bfs() {
    queue<Node> q;
    q.push(Node(S, 0));
    xuoi[S] = 0;
    while (!q.empty()) {
        Node x = q.front(); q.pop();
        if (x.config == T) {
            stop = 1;
            cout << x.high;
            return;
        }
        if (x.high > 15) return;
        rot(x.config);
        if (xuoi.find(le) == xuoi.end()) {
            q.push(Node(le, x.high + 1));
            xuoi[le] = x.high + 1;
        }
        if (xuoi.find(ri) == xuoi.end()) {
            q.push(Node(ri, x.high + 1));
            xuoi[ri] = x.high + 1;
        }
    }
}
void bfs_reverse() {
    queue<Node> q;
    q.push(Node(T, 0));
    nguoc[T] = 0;

    while (!q.empty()) {
        Node x = q.front(); q.pop();
        if (xuoi.find(x.config) != xuoi.end()) {
            cout << x.high + xuoi[x.config];
            return;
        }

        rot_reverse(x.config);
        if (nguoc.find(le) == nguoc.end()) {
            q.push(Node(le, x.high + 1));
            nguoc[le] = x.high + 1;
        }
        if (nguoc.find(ri) == nguoc.end()) {
            q.push(Node(ri, x.high + 1));
            nguoc[ri] = x.high + 1;
        }
    }
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
	    for (int i = 1; i <= 10; ++i) {
	        int x; cin >> x;
	        S += char(x + '0');
	    }
	    bfs();
	    if (!stop) bfs_reverse();
	    stop = 0;
	    S.clear();
	    xuoi.clear();
	    nguoc.clear();
	    cout << ed;
	}
	return BidenJr;
}
