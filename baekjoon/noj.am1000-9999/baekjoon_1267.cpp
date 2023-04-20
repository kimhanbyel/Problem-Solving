#include <iostream>
using namespace std;

int n, num1, num2, a, b;
int main(){
	cin >> n;
	
	while(n--){
		cin >> num1; num2=num1;
		
		a+=(num1/30)*10, b+=(num2/60)*15;
		if(num1%30>=0) a+=10;
		if(num2%60>=0) b+=15;
	}
	
	cout << a << " " << b;
	if(a > b)
		cout << "M " << b;
	else if(a < b)
		cout << "Y " << a;
	else
		cout << "Y M " << a;
}
