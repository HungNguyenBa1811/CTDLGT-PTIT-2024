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

struct Node {
	int data;
	Node *l;
	Node *r;
	Node(int x){
		this->data = x;
	}
};

typedef struct Node* node;

int u, v;
char x;

void build(node root){
	if(root == NULL) return;
	if(root->data == u){
		if(x == 'L') root->l = new Node(v);
		else root->r = new Node(v);
	} else {
		build(root->l);
		build(root->r);
	}
}

void levelOrder(node root){
	if(root == NULL) return;
	queue<node> q;
	q.push(root);
	while(!q.empty()){
		node tmp = q.front();
		cout << tmp->data << " ";
		q.pop();
		if(tmp->l != NULL) q.push(tmp->l);
		if(tmp->r != NULL) q.push(tmp->r);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		node root = NULL;
		while(n--){
			cin >> u >> v >> x;
			if(root == NULL){
				root = new Node(u);
			}
			build(root);
		}
		levelOrder(root);
		cout << ed;
	}
	return BidenJr;
}
