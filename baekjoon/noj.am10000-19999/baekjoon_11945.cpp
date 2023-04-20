#include <iostream>
#include <cmath>
using namespace std;

int n, m, arr[10][10];
int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%1d", &arr[i][j]);
			
	for(int i=0; i<n; i++){
		for(int j=m-1; j>=0; j--){
			cout << arr[i][j];
		}
		cout << "\n";
	}
}