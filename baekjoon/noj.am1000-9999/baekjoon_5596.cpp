#include <iostream>
using namespace std;

int n, asum, bsum;
int main(){
	for(int i=0; i<8; i++){
		cin >> n;
		if(i<4) asum += n;
		else	bsum += n; 
	}	cout << max(asum, bsum);
}