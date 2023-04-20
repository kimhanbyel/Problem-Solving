#include <iostream>
using namespace std;

int n, t, a, b;
int main(){
	cin >> n;
	
	while(n--){
		cin >> t;
		a+=t/30*10+10;
		b+=t/60*15+15;
	}

	if(a!=b)
		cout << ((a>b) ? "M ":"Y ") << ((a>b) ? b:a);
	else
		cout << "Y M " << a;
}
