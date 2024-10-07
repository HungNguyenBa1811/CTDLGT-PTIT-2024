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

int dungbeu[1001];
int mo, beu_check, thucan;

int kiemtrahamluongmo(){
	int lipit = 0;
	for(int i = 1; i <= mo; i++) if(dungbeu[i]) lipit++;
	if(thucan == lipit) return 1;
	return 0;
}

void ktao(){
	for(int i = 1; i <= mo; i++) dungbeu[i] = 0;
}

void in(){
	for(int i = 1; i <= mo; i++) cout << dungbeu[i];
}

void somo(){
	int i = mo;
	while(i > 0 && dungbeu[i]){
		dungbeu[i] = 0;
		i--;
	}
	if(i == 0) beu_check = 0;
	else dungbeu[i] = 1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> mo >> thucan;
		ktao();
		beu_check = 1;
		while(beu_check){
			if(kiemtrahamluongmo()){
				in();
				cout << ed;
			}
			somo();
		}
	}
	return BidenJr;
}

