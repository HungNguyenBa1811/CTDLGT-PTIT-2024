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

struct Node{
	int val;
	Node *l, *r;
	Node(int x){
		// Make node quick
		val = x;
		l = r = NULL;
	}
};

// tao node
void makeNode(Node *root, int u, int v, char c){
	if(c == 'L') root->l = new Node(v);
	else root->r = new Node(v);
}

// them 1 node vao cay
void insert(Node *root, int u, int v, char c){
	// duyet het cay de them node
	if(root == NULL) return;
	if(root->val == u){
		makeNode(root, u, v, c);
	}
	insert(root->l, u, v, c);
	insert(root->r, u, v, c);
}

int height(Node *root){
	if(root == NULL) return 0;
	return 1 + max(height(root->l), height(root->r));
}

bool identical(Node *root1, Node *root2){
	if(root1 == NULL && root2 == NULL){
		return true;
	}
	if(root1 != NULL && root2 != NULL){
		return (root1->val == root2->val) && identical(root1->l, root2->l) && identical(root1->r, root2->r);
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		Node* root1 = NULL;
		while(n--){
			int u, v;
			char c;
			cin >> u >> v >> c;
			if(root1 == NULL){
				root1 = new Node(u);
				makeNode(root1, u, v, c);
			} else {
				insert(root1, u, v, c);
			}
		}
		int m; cin >> m;
		Node* root2 = NULL;
		while(m--){
			int u, v;
			char c;
			cin >> u >> v >> c;
			if(root2 == NULL){
				root2 = new Node(u);
				makeNode(root2, u, v, c);
			} else {
				insert(root2, u, v, c);
			}
		}
		if(identical(root1, root2)) cout << 1 << ed;
		else cout << 0 << ed;
	}
	return BidenJr;
}
