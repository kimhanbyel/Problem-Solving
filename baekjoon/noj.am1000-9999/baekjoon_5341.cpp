#include <iostream>
using namespace std;

int n;
int main(){
	while(1){
		cin >> n;
		if(!n) return 0;
		
		int ans = 0;
		for(int i=1; i<=n; i++)	
			ans += i;
			
		cout << ans << "\n";
	}
}