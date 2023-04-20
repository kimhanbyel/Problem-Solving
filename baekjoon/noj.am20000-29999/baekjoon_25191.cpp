#include <iostream>
using namespace std;

int n, a, b;
int main(){
	cin >> n >> a >> b;
	if((a/2)+b>n) cout << n;
	else		  cout << (a/2)+b;
}