#include <iostream>
using namespace std;

long long f(long long n){
	if(n <= 1)
		return 1;
		
	return n*f(n-1);
} 

int main(){
	long long n, m;
	cin >> n >> m;
	cout << f(n)/(f(m) * f(n-m));
}
