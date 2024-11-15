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

vector<int> bag;
vector<int> value;
vector<pair<string, int>> ans;
string s = "";
int n, w;

void Try(int i){
	if(i == n){
		int kl = 0, res = 0;
		for(int i = 0; i < n; i++){
			kl += (s[i] - '0') * bag[i];
			res += (s[i] - '0') * value[i];
		}
		if(kl <= w){
			ans.push_back({s, res});
		} 
		return;
	}
	for(int j = 0; j <= 1; j++){
		s += to_string(j);
		Try(i + 1);
		s.pop_back();		
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> w;
	for(int i = 0; i < n; i++){
		int a; cin >> a; value.push_back(a);
	}	
	for(int i = 0; i < n; i++){
		int a; cin >> a; bag.push_back(a);
	}
	Try(0);
	int fotp = 0;
	for(auto x : ans){
		fotp = max(fotp, x.second);
	}
	cout << fotp << ed;
	for(auto x : ans){
		if(x.second == fotp){
		    for(char xx : x.first) cout << xx << " ";
		}
	}
	return BidenJr;
}
