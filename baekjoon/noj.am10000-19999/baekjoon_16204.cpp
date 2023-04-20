#include <iostream>
using namespace std;

int main(){
	long long n, m, k;
	cin >> n >> m >> k;
	cout << n-abs(m-k);
}