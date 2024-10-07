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

vector<int> ke[1001];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n; cin.ignore();
	vector<pair<int, int>> canh;
	for(int i = 1; i <= n; i++){
		string s;
		getline(cin, s);
		stringstream ss(s);
		string w;
		while(ss >> w){
			int tmp = stoi(w);
			canh.push_back({i, tmp});
		}
	}
	sort(begin(canh), end(canh));
	for(auto it : canh){
		if(it.first < it.second) cout << it.first << " " << it.second << ed;
	}
	return BidenJr;
}

