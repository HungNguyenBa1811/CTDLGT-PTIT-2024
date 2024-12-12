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

struct node {
	int data;
	node *l;
	node *r;
	node(int data){
		this->data = data;
	}
};

int u, v;
char x;

void build(node *root){
	if(root == NULL) return;
	if(root->data == u){
		if(x == 'L') root->l = new node(v);
		else root->r = new node(v);
	} else {
		build(root->l);
		build(root->r);
	}
}

int lvl;

bool check(node *root){
	queue<pair<node*, int>> q;
	q.push({root, 0});
	while(!q.empty()){
		auto tmp = q.front(); q.pop();
		if(tmp.first->l == NULL && tmp.first->r == NULL){
			if(lvl == -123) lvl = tmp.second;
			else {
				if(lvl != tmp.second) return false;
			}
		}
		if(tmp.first->l != NULL){
			q.push({tmp.first->l, tmp.second + 1});
		}
		if(tmp.first->r != NULL){
			q.push({tmp.first->r, tmp.second + 1});
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		node *root = NULL;
		while(n--){
			cin >> u >> v >> x;
			if(root == NULL){
				root = new node(u);
			}
			build(root);
		}
		lvl = -123;
		cout << (check(root) ? "1" : "0") << ed;
	}
	return BidenJr;
}
