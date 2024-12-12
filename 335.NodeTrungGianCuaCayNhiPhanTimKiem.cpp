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

Node *build(int *pre, int n){
	if(n <= 0) return NULL;
	Node *root = new Node(pre[0]);
	int idx = n;
	for(int i = 1; i < n; i++){
		if(pre[i] > pre[0]){
			idx = i;
			break;
		}
	}
	root->l = build(&pre[1], idx - 1);
	root->r = build(&pre[idx], n - idx);
	return root;
}

int cnt(Node *root){
	if(root == NULL || (root->l == NULL && root->r == NULL))
		return 0;
	return 1 + cnt(root->l) + cnt(root->r);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int pre[n];
		for(int i = 0; i < n; i++) cin >> pre[i];
		Node *root = build(pre, n);
		cout << cnt(root) << ed;
	}
	return BidenJr;
}

