#include <iostream>
using namespace std;

int main(){
	int n, m, a, b, arr[101]={};
	cin >> n >> m;
	
	for(int i=1; i<=n; i++)
		arr[i] = i;
		
	for(int i=1; i<=m; i++){
		cin >> a >> b;
		
		for(int c=a, d=b; c<=d; c++, d--){
			int temp = arr[c];
			arr[c] = arr[d];
			arr[d] = temp;
		}
	}
	
	for(int i=1; i<=n; i++)
		cout << arr[i] << " ";
}
