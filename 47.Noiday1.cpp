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

// Tham lam noi day:

// De bai: Cho soi day, tim chi phi it nhat de noi day
// VD: 4 3 2 9
// Gia su chon 4 noi 3 -> 7, 2, 9, chi phi la 7
// Tiep chon 7 noi 2 -> 9, 9, chi phi la 7 + 9
// Cuoi 9 noi 9 -> 18, chi phi la 7 + 9 + 18

// HOW TO THAM LAM: Chon 2 day ngan nhat noi nhau -> chi phi ngan nhat
// Sol 1: sort mang -> sieu lau cuz chon xong thi xoa xong lai insert vao roi sort tiep
// Sol 2: multiset // priority queue -> xoa: logn, insert: logn -> toi uu

// Vidu priority queue
//priority_queue<int> Q; max heap
//Q.push(1);
//Q.top(); tra ve phan tu lon nhat
//Q.pop();
//Q.empty;
//Q.size();

//priority_queue<int, vector<int>, greater<int>> Q; min heap

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		priority_queue<int, vector<int>, greater<int>> Q;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			Q.push(x);
		}
		int ans = 0;
		while(Q.size() != 1){
			int tmp = Q.top();
			Q.pop();
			tmp += Q.top();
			Q.pop();
			Q.push(tmp);
			ans += tmp;
		}
		cout << ans << ed;
	}
	return BidenJr;
}

