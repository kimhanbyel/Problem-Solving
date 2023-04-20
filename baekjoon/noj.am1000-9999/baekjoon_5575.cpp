#include <iostream>
#include <cmath>
using namespace std;

int a, b, c;
int main(){
	for(int i=1; i<=3; i++){
		cin >> a >> b >> c;
		int t = a*3600+b*60+c;
		cin >> a >> b >> c;
		t = a*3600+b*60+c-t;
		cout << t/3600 << " " << (t%3600)/60 << " " << (t%3600)%60 << "\n";
	}	
}