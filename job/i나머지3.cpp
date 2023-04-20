#include <iostream>
using namespace std;

void f(int i, int j){
	if(i%3==1 && j&3==1)
    	cout << " ";
    else
    	cout << "*";
}

int main(){
	int n;	 
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
        	f(i, j);
		}
		cout << "\n";
	}
}
