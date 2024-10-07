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

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod){
    if(n == 0) return;
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << from_rod << " -> " << to_rod << ed;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	towerOfHanoi(n, 'A', 'C', 'B');
	return BidenJr;
}

