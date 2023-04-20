#include <iostream>
using namespace std;

int main(){
	char a;
	cin >> a;
	if(a=='N' || a=='n') cout << "Naver D2";
	else				 cout << "Naver Whale";
}
/* short coding
#include <iostream>
int main(){char a;std::cin >> a;std::cout<<"Naver "<<(a=='n'||a=='N'?"D2":"Whale");}
*/