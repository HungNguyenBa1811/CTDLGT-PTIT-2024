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

Node *build(int pre[], int *idx, int l, int r, int n){
	if(*idx >= n || l > r)
		return NULL;
	// Chon lam goc
	Node *root = new Node(pre[*idx]);
	(*idx)++;
	// Tim nhanh tiep theo
	if(l == r) return root;
	int ans; 
	for(int i = l; i <= r; i++){
		if(pre[i] > root->val){
			ans = i;
			break;
		}
	}
	root->l = build(pre, idx, *idx, ans - 1, n);
	root->r = build(pre, idx, ans, r, n);
	return root;
}

void postOrder(Node *root){
	if(root == NULL) return;
	postOrder(root->l);
	postOrder(root->r);
	cout << root->val << " ";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int pre[n];
		for(int i = 0; i < n; i++) cin >> pre[i];
		int idx = 0;
		Node *root = build(pre, &idx, 0, n - 1, n);
		postOrder(root);
		cout << ed;
	}
	return BidenJr;
}
