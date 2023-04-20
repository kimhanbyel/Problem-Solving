#include <iostream>
using namespace std;

int main(){
	int a;
	char ans = 'S';
	for(int i=0; i<8; i++){
		cin >> a;
		if(a>1) ans = 'F';
	}	cout << ans;
}