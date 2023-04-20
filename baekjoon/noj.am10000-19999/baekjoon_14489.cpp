#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long long a, b, c;
	cin >> a >> b >> c;
	if(a+b>c*2) cout << (a+b)-c*2;
	else		cout << a+b; 
}