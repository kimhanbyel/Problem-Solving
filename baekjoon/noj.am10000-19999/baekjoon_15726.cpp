#include <iostream>
using namespace std;

long long a, b, c, x, y;
int main(){
	cin >> a >> b >> c;
	x = a*((double)b/c);
	y = ((double)a/b)*c;
	cout << (long long)max(x, y);
}                                       
                                 