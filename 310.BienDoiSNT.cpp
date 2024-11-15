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

bool checknt(int a){ 
	if(a < 2) return false;
	for(int i = 2; i <= sqrt(a); i++) 
		if(a % i == 0)
			return false; 
	return true;
} 

int BFS(int s, int t){
	int visited[10001] = {0};
	queue<pair<int, int>> q;
	q.push({s, 0});
	visited[s] = 1;
	while(!q.empty()){
		pair<int, int> tmp = q.front();
		q.pop();
		if(tmp.first == t) return tmp.second;
		string x = to_string(tmp.first);
		for(int i = 0; i < 4; i++){
			for(int j = 0; j <= 9; j++){
				string a = x;
				a[i] = j + '0';
				if(a[0] != '0'){
					int _a = stoi(a);
					if(!visited[_a] && checknt(_a)){
						q.push({_a, tmp.second + 1});
						visited[_a] = 1;
					}
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int s, t;
		cin >> s >> t;
		cout << BFS(s, t) << ed;
	}
	return BidenJr;
}

