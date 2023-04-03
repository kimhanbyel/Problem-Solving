#include <iostream>
#include <algorithm>
using namespace std;

int a[2];
int main(){
	for(;;){
		cin >> a[0] >> a[1] >> a[2];
		if(a[0]+a[1]+a[2] == 0) return 0;
		// 2 3 5, 
		
		sort(a, a+3);
//		cout << a[0] << a[1] << a[2];
		if(a[2] >= a[1]+a[0]) cout << "Invalid\n";
		else if(a[0]==a[1] && a[1]==a[2]) cout << "Equilateral\n";
		else if(a[0]==a[1] || a[1]==a[2] || a[0]==a[2]) cout << "Isosceles";
		else cout << "Scalene\n";
	}
}
