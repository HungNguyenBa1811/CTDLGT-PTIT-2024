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

char a[100][100];
int k, m, n;
string s = "";
set<string> dict;
bool visited[100][100];
vector<string> res;

void Try(int i, int j){
	s += a[i][j];
	if(dict.count(s)) res.push_back(s);
	for(int k = 0; k < 8; k++){
		int i1 = i + x_8axis[k];
		int j1 = j + y_8axis[k];
		if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1]){
			visited[i1][j1] = 1;
			Try(i1, j1);
			visited[i1][j1] = 0;
		}
	}
	s.pop_back();
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> k >> m >> n;
		memset(visited, 0, sizeof(visited));
		dict.clear();
		res.clear();
		for(int i = 0; i < k; i++){
			string w; cin >> w;
			dict.insert(w);
		}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> a[i][j];
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				s = "";
				Try(i, j);
			}			
		}
		if(res.empty()) cout << -1;
		else {
    		for(string x : res){
    			cout << x << " ";
    		}
		}
		cout << ed;
	}
	return BidenJr;
}
