#include <iostream>
#include <list>
#define lb l.begin()
#define le l.end()
using namespace std;

int main(){
	int a;
	string b;
	cin >> a;
	while(a--){
		list<char> l {};
		list<char>::iterator cur = le;
		
		cin >> b;
		for(auto c : b){
			if(c == '<'){if(cur != lb && !l.empty()) cur--;}
			else if(c == '>'){if(cur != le && !l.empty()) cur++;}
			else if(c == '-'){if(cur != lb && !l.empty()) l.erase(--cur);}
			else l.insert(cur, c);
		}
		for(auto c : l){
			cout << c ;
		}	cout << '\n';
	}
	
	return 0;
}
