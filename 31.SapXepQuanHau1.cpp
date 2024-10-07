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

int X[100], cot[100], d1[100], d2[100];
int n, cnt;

void Try(int i){
	for(int j = 1; j <= n; j++){
		if(cot[j] == 0 && d1[i - j + n] == 0 && d2[i + j - 1] == 0){
			X[i] = j;
			cot[j] = 1;
			d1[i - j + n] = 1;
			d2[i + j - 1] = 1;
			if(i == n){
				cnt++;
			}
			Try(i + 1);
			cot[j] = 0;
			d1[i - j + n] = 0;
			d2[i + j - 1] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n;
		cnt = 0;
		memset(cot, 0, sizeof(cot));
		memset(d1, 0, sizeof(d1));
		memset(d2, 0, sizeof(d2));
		Try(1);
		cout << cnt << ed;		
	}
	return BidenJr;
}

