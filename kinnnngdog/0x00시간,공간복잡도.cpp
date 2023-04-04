#include <iostream>
using namespace std;

long long func1(int n, long long result){
	if(n==0)
		return result;
	
	if(n%3==0 || n%5==0)
		result += n;
		
	return func1(n-1, result);
}

int main(){
	int n;
	cin >> n;
	cout << func1(n, 0);
}
