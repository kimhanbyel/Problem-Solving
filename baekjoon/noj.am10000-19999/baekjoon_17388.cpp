#include <iostream>
#include <cmath>
using namespace std;

int a, b, c, m, i;
int main(){
	cin >> a >> b >> c;
	if(a+b+c >= 100){
		cout << "OK";
		return 0;
	}
	m = min(a, min(b, c));
	if(m==a) cout << "Soongsil";
	else if(m==b) cout << "Korea";
	else cout << "Hanyang";
}