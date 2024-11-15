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

vector<int> res;

void sieve(){
	for(int i = 0; i <= 5; i++) res.push_back(i);
	queue<pair<int, vector<int>>> q;
	q.push({1, {0, 1, 0, 0, 0, 0}});
	q.push({2, {0, 0, 1, 0, 0, 0}});
	q.push({3, {0, 0, 0, 1, 0, 0}});
	q.push({4, {0, 0, 0, 0, 1, 0}});
	q.push({5, {0, 0, 0, 0, 0, 1}});
	while(1){
		auto top = q.front(); q.pop();
		int x = top.first;
		if(x > 100000) break;
		vector<int> tmp = top.second;
		for(int i = 0; i <= 5; i++){
			if(tmp[i] == 0){
				tmp[i] = 1;
				q.push({x * 10 + i, tmp});
				res.push_back(x * 10 + i);
				tmp[i] = 0;
			}
		}
	}	
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	sieve();
	while(t--){
		int l, r;
		cin >> l >> r;
		int idx1 = lower_bound(res.begin(), res.end(), l) - res.begin();
		int idx2 = lower_bound(res.begin(), res.end(), r) - res.begin();
		if(res[idx2] != r) idx2--;
		cout << idx2 - idx1 + 1 << ed;
	}
	return BidenJr;
}

