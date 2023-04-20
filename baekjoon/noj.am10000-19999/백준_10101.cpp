#include <iostream>
using namespace std;

int a[3]={}; // angle
int main(){
	cin >> a[0] >> a[1] >> a[2];
	if(a[0]+a[1]+a[2] == 180){
		if(a[0] == a[1] && a[1] == a[2])
			cout << "Equilateral";
		else if(a[0]==a[1] || a[1]==a[2] || a[0]==a[2])
			cout << "Isosceles";
		else
			cout << "Scalene";
	}
	else
		cout << "Error";
}
