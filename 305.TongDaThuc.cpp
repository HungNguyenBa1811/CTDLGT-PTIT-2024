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
    int heso;
    int somu;
    Node *next;
};

typedef struct Node* node;

node makeNode(int x, int y) {
    node tmp = new Node();
    tmp->heso = x;
    tmp->somu = y;
    tmp->next = NULL;
    return tmp;
}

void insertLast(node &a, int x, int y) {
    node tmp = makeNode(x, y);
    if (a == NULL) {
        a = tmp;
    } else {
        node p = a;
        while (p->next != NULL) p = p->next;
        p->next = tmp;
    }
}

node addNode(node x, node y) {
    node z = new Node();
    node head = z;

    while (x != NULL && y != NULL) {
        if (x->somu > y->somu) {
            z->next = makeNode(x->heso, x->somu);
            x = x->next;
        } else if (x->somu < y->somu) {
            z->next = makeNode(y->heso, y->somu);
            y = y->next;
        } else {
            z->next = makeNode(x->heso + y->heso, x->somu);
            x = x->next;
            y = y->next;
        }
        z = z->next;
    }
    while (x != NULL) {
        z->next = makeNode(x->heso, x->somu);
        z = z->next;
        x = x->next;
    }
    while (y != NULL) {
        z->next = makeNode(y->heso, y->somu);
        z = z->next;
        y = y->next;
    }
    return head->next;
}

void printNode(node a) {
    while (a != NULL) {
        cout << a->heso << "*x^" << a->somu;
        if (a->next != NULL) cout << " + ";
        a = a->next;
    }
    cout << ed;
}

void input(string s, node &a) {
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            int heso = 0, somu = 0;
            while (isdigit(s[i]) && i < s.size()) {
                heso = heso * 10 + (s[i] - '0');
                i++;
            }
            i += 3;
            while (isdigit(s[i]) && i < s.size()) {
                somu = somu * 10 + (s[i] - '0');
                i++;
            }
            insertLast(a, heso, somu);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t; cin.ignore();
    while (t--) {
        node head1 = NULL;
        node head2 = NULL;
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        input(s1, head1);
        input(s2, head2);
        node result = addNode(head1, head2);
        printNode(result);
    }
    return BidenJr;
}

