#include <iostream>
#include <cmath>
using namespace std;

long long a, b, n;
int main(){
	cin >> a >> b >> n;
	if(a%n) a = a/n+1;
	else	a = a/n;
	if(b%n) b = b/n+1;
	else	b = b/n;
	
	cout << a*b;
}

/*
3 3 3 7 1 1 1
3 3 3 7 1 1 1 
3 3 3 7 1 1 1 
4 4 4 8 2 2 2
4 4 4 8 2 2 2
4 4 4 8 2 2 2 
5 5 5 9 6 6 6
*/