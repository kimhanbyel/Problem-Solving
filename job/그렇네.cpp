#include <iostream>
using namespace std;

long long p(long long n){
	if(n<=1) return 1;
	return n*p(n-1);
}

int main(){
	long long n, m, T;
	cin >> T;
	
	while(T--){
		cin >> n >> m;
		long long a = p(m);
		long long b = p(n);
		long long c = p(m-n);
		cout << p(m)/(p(n)*p(m-n)) << endl;
	}
}
