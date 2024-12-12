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

struct node{
	int data;
	node *l = NULL;
	node *r = NULL;
	node(int data){
		this->data = data;
	}
};

int n, lvl[1001];
map<int, int> idxOf;

node *build(int i, int l, int r){
	if(i >= n || l > r) return NULL;
	node *root = new node(lvl[i]);
	int m = idxOf[lvl[i]];
	root->l = build(i * 2 + 1, l, m - 1);
	root->r = build(i * 2 + 2, m + 1, r);
	return root;
}

void postOrder(node *root){
	if(root == NULL) return;
	postOrder(root->l);
	postOrder(root->r);
	cout << root->data << " ";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			idxOf[x] = i;
		}
		for(int i = 0; i < n; i++){
			cin >> lvl[i];
		}
		node *root = build(0, 0, n - 1);
		postOrder(root);
		cout << ed;
		idxOf.clear();
	}
	return BidenJr;
}
