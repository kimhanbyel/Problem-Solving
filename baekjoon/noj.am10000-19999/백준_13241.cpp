#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long long a, b;
	cin >> a >> b;
	cout << a*b/__gcd(a,b);
} 
