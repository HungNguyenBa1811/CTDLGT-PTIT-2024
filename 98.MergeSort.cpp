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

void merge(int arr[], int l, int m, int r){ 
    int n1 = m - l + 1, n2 = r - m; 
    int L[n1], R[n2]; 
    for(int i = 0; i < n1; i++) L[i] = arr[l + i]; 
    for(int j = 0; j < n2; j++) R[j] = arr[m + 1 + j]; 
    int i = 0, j = 0, k = l; 
    while (i < n1 && j < n2){ 
        if(L[i] <= R[j]){ 
            arr[k] = L[i]; 
            i++; 
        } else {
            arr[k] = R[j]; 
            j++;
        } 
        k++; 
    } 
    while(i < n1){ 
        arr[k] = L[i]; 
        i++; 
        k++; 
    }
    while(j < n2){ 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(int arr[], int l, int r) { 
    if (l < r){ 
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    } 
} 
  

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		mergeSort(a, 0, n - 1);
		for(int i = 0; i < n; i++) cout << a[i] << " ";
		cout << ed;
	}
	return BidenJr;
}

