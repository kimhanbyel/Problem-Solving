#include <iostream>
using namespace std;

void f(int a, int b){
	if(a){
		f(a/b, b);
		cout << char(a%b<10 ? a%b+'0' : a%b+'A'-10);
	}
	return;
}

int main(){
	int a, b;
	cin >> a >> b;
	f(a, b);
}
