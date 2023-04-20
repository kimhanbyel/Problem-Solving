#include <iostream>
using namespace std;

int main(){
	int n, m , arr[101]={};
	int a, b, c;
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		cin >> a >> b >> c;
		for(int j=a; j<=b; j++)
			arr[j-1] = c;
	}
	
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
}
