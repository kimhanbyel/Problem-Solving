#include <iostream>
#include <algorithm>
using namespace std;

int a[3];
int main(){
	cin >> a[0] >> a[1] >> a[2];
	
	sort(a, a+3);
	while(a[2]){
		if(a[2]>=a[1]+a[0]) a[2]--;
		else break;
	}
	cout << a[0] + a[1] + a[2];
}
