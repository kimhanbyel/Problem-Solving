#include <iostream>
using namespace std;

int main(){
	int z=0, input;
	for(int i=0; i<12; i++){
		cin >> input;
		if(!input) z++;
		
		if(i%4 == 3){
			if(z==1)
				cout << "A\n";
			else if(z==2)
				cout << "B\n";
			else if(z==3)
				cout << "C\n";
			else if(z==4)
				cout << "D\n";
			else
				cout << "E\n";
				
			z=0;
		}
	}
}
