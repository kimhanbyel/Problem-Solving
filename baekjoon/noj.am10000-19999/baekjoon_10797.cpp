#include <iostream>
using namespace std;

int a, b, ans;
int main(){
	cin >> a;
	for(int i=0; i<5; i++){
		cin >> b;
		if(a==b) ans++;
	}	cout << ans;
}