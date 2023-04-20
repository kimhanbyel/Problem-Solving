#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	n%=8; // 9 = 1 // 1 
	if(n>5 || n==0) cout << (10-n)%8;
	else  cout << n;
}