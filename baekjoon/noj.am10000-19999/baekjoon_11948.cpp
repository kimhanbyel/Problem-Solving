#include <iostream>
using namespace std;

int a, ans, mi1=101, mi2=101;
int main(){
	for(int i=0; i<6; i++){
		cin >> a; ans+=a;
		if(i<4)	mi1 = min(mi1, a);
		else	mi2 = min(mi2, a);
	}	cout << ans-mi1-mi2;
}