#include <iostream>
using namespace std;

int T, n, ans, c[100001]={};
void DFS(int i, int arr[]){
	if(c[arr[i]] == 0) {c[i]++; DFS(arr[i], arr);}
	else ans++;
}
int main(){
	cin >> T;
	while(T--){
		int arr[100001]={};
		ans = 0;
		
		cin >> n;
		for(int i=1; i<=n; i++){ c[i]=0; cin >> arr[i];}
		for(int i=1; i<=n; i++) DFS(i, arr);
		cout << ans;
	}
}