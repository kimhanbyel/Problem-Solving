#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a = n/10; // 101 이라면 a = 10이 나옴
	int b = n%100; // 110 이라면 b= 10이 나옴
	
	if(a>10) a/=10;
	if(b>10) b%=10;
	
	cout << a+b;
}