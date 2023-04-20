#include <iostream>
using namespace std;

int a, b;
int main(){
	cin >> a >> b;
	if(a+b<0 || a-b<0 || (a+b)%2) cout << -1;
	else{
		cout << (a+b)/2 << " " << (a-b)/2;
	}
}
/*
10 6
8 2
*/