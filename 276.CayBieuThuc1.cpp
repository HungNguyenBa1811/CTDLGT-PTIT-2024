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
	char data;
	node *l = NULL;
	node *r = NULL;
	node(char data){
		this->data = data;
	}
};

void inOrder(node *root){
	if(root == NULL) return;
	inOrder(root->l);
	cout << root->data << " ";
	inOrder(root->r);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		stack<node*> st;
		for(char x : s){
			if(isalpha(x)) st.push(new node(x));
			else {
				node *sign = new node(x);
				sign->r = st.top(); st.pop();
				sign->l = st.top(); st.pop();
				st.push(sign);
			}
		}
		inOrder(st.top());
		cout << ed;
	}
	return BidenJr;
}
