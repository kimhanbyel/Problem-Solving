#include <iostream>
using namespace std;

int main(){
	int T, a, ans=0;
	cin >> T;
	while(T--){
		cin >> a;
		ans += a;
	}
	cout << ans;
}
