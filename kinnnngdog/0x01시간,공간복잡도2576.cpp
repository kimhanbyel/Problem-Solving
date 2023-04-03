#include <iostream>
using namespace std;

int main(){
	int n, min=101, sum=0;
	for(int i=0; i<7; i++){
		cin >> n;
		if(n%2==1){
			sum += n;
			if(n < min) min=n;
		}
	}
	if(sum) cout << sum << '\n' << min;
	else cout << -1;
}
