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

// Idea: duyet tuan tu tren pre[], su dung idxOf (inorder) lam bien check
int n, pre[1001], cur_i;
map<int, int> idxOf;

node *build(int l, int r){
	if(l > r) return NULL;
	node *root = new node(pre[cur_i]);
	// tim index cua phan tu pre[i] tren inorder array voi i la vi tri hien tai
	int m = idxOf[pre[cur_i]]; cur_i++;
	root->l = build(l, m - 1);
	root->r = build(m + 1, r);
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
			cin >> pre[i];
		}
		cur_i = 0;
		node *root = build(0, n - 1);
		postOrder(root);
		cout << ed;
		idxOf.clear();
	}
	return BidenJr;
}
