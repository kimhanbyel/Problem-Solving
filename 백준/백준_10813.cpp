#include <iostream>
using namespace std;

int main(){
	int n, m, a, b, arr[101]={};
	cin >> n >> m;
	
	for(int i=1; i<=n; i++)
		arr[i] = i;
		
	for(int i=1; i<=m; i++){
		cin >> a >> b;
		
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp; 
	}
	
	for(int i=1; i<=n; i++)
		cout << arr[i] << " ";
}
