#include <iostream>
#include <algorithm>
using namespace std;

int a, b;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(1){
		cin >> a >> b;
		if(a+b==0) break;
		cout << a+b << "\n";
	}
}