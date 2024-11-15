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

int BFS(vector<int> &a, vector<int> &b){
	queue<pair<vector<int>, int>> q;
	map<vector<int>, int> visited;
	q.push({a, 0});
	visited[a] = 1;
	int x, y, z, u;
	while(!q.empty()){
		pair<vector<int>, int> tmp = q.front();
		q.pop();
		if(tmp.first == b) return tmp.second;
		
        vector<int> x1 = tmp.first;
        x = x1[0], y = x1[1], z = x1[3], u = x1[4];
        x1[0] = z;
        x1[1] = x;
        x1[4] = y;
        x1[3] = u;
        if (!visited[x1]) {
            q.push({x1, tmp.second + 1});
            visited[x1] = true;
        }
        
        vector<int> x2 = tmp.first;
        x = x2[1], y = x2[2], z = x2[4], u = x2[5];
        x2[1] = z;
        x2[2] = x;
        x2[5] = y;
        x2[4] = u;
        if (!visited[x2]) {
            q.push({x2, tmp.second + 1});
            visited[x2] = true;
        }
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		vector<int> a(6);
		vector<int> b(6);
		for(int i = 0; i < 6; i++) cin >> a[i];
		for(int i = 0; i < 6; i++) cin >> b[i];
		cout << BFS(a, b) << ed;
	}
	return BidenJr;
}

