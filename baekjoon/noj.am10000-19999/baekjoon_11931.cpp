#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[1000001]={};
bool cmd(int a, int b){return a>b;}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i=0;i<n;i++) cin >> arr[i];
	sort(arr, arr+n, cmd);
	for(int i=0;i<n;i++) cout << arr[i] << '\n';
}

/*

10

*/