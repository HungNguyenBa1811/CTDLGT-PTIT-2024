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

Node *build(vector<int>& in, int l, int r){
	if(l > r) return NULL;
	int m = l + (r - l) / 2;
	Node *root = new Node(in[m]);
	root->l = build(in, l, m - 1);
	root->r = build(in, m + 1, r);
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
		vector<int> in(n);
		for(int i = 0; i < n; i++) cin >> in[i];
		sort(begin(in), end(in));
		Node *root = build(in, 0, n - 1);
		postOrder(root);
		cout << ed;
	}
	return BidenJr;
}
