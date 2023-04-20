#include <iostream>
using namespace std;

int a, b, c, d, e, ans;
int main(){
	cin >> a >> b >> c >> d >> e;
	if(a<0) cout << (abs(a)*c)+d+(b*e);
	else 	cout << (b-a)*e;
}