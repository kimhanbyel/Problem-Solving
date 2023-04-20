#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int T, a, b;
	cin >> T;
	while(T--){
		cin >> a >> b;
		cout << a*b/__gcd(a, b) << '\n';
	}
} 
