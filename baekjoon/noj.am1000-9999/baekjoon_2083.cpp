#include <iostream>
using namespace std;

int main(){
	string s;
	int age, kg;
	while(1){
		cin >> s >> age >> kg;
		if(s=="#" && age+kg == 0) break;
		if(age>=17 || kg>=80) cout << s << " Senior\n";
		else				  cout << s << " Junior\n";
	}
}