#include <iostream>
using namespace std;

int main(){
	int n;
	string s;
	cin >> n;
	while(n--){
		cin >> s;
		for(auto a:s){
			if(a<='Z') cout << char(a+' ');
			else	   cout << char(a);
		}
		cout << "\n";
	}
}