#include <iostream>
using namespace std;

int n, k, s, y, arr[2][7], roomCnt;
int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> s >> y;
		arr[s][y]++;
	}
	for(int i=0; i<=1; i++)
		for(int j=1; j<=6; j++)
			roomCnt += arr[i][j]%k ? arr[i][j]/k+1 : arr[i][j]/k;
			
	cout << roomCnt;
}
