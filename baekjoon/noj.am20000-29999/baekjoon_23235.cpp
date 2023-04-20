#include <iostream>
using namespace std;

int a, n, cnt=1;
int main(){
	while(1){
		cin >> n;
		if(!n) return 0;
		
		for(;n--;) cin >> a;
		cout << "Case " << cnt++ << ": Sorting... done!\n";
	}
}