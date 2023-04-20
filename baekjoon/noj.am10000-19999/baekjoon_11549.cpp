#include <iostream>
using namespace std;

long long t,a, ans;
int main(){
	cin >> t;
	for(int i=0; i<5; i++){
		cin >> a;
		if(a==t) ans++;
	}	cout << ans;
}