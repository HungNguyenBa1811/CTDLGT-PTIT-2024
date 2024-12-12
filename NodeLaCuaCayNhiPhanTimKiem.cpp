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
		val = x;
		l = r = NULL;
	}
};

Node *build(vector<int>& pre, int l, int r){
	if(l > r) return NULL;
	Node *root = new Node(pre[l]);
	int i;
	for(i = l + 1; i <= r; i++){
		if(pre[i] > root->val){
			break;
		}
	}
	root->l = build(pre, l + 1, i - 1);
	root->r = build(pre, i, r);
	return root;
}

void findLeaf(Node *root){
	if(root->l == NULL && root->r == NULL){
		cout << root->val << " ";
		return;
	}
	if(root->l) findLeaf(root->l);
	if(root->r) findLeaf(root->r);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> pre(n);
		for(int i = 0; i < n; i++) cin >> pre[i];
		Node *root = build(pre, 0, n - 1);
		findLeaf(root);
		cout << ed;
	}
	return BidenJr;
}
