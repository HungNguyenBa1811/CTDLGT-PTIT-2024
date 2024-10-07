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

struct First{
	int data;
	First *next;
};

typedef struct First* node;

node makeNode(int x){
	node tmp = new First();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

void insertLast(node &a, int x){
	node tmp = makeNode(x);
	if(a == NULL){
		a = tmp;
	} else {
		node p = a;
		while(p->next != NULL) p = p->next;
		p->next = tmp;
	}
}

void deleteAllNode(node &a, int val){
	while(a != NULL && a->data == val){
		a = a->next;
	}
	node p = a;
	while(p != NULL && p->next != NULL){
		if(p->next->data == val){
			p->next = p->next->next;
		} else {
			p = p->next;
		}
	}
}

void printNode(node a){
	while(a != NULL){
		cout << a->data << " ";
		a = a->next;
	}
}

int main(){
	node head = NULL;
	int n; cin >> n;
	while(n--){
		int x; cin >> x;
		insertLast(head, x);
	}
	int k; cin >> k;
	deleteAllNode(head, k);
	printNode(head);
	return BidenJr;
}
