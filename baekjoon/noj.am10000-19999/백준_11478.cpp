#include <iostream>
#include <set>
using namespace std;

int main(){
	string a;
	cin >> a;
	
	set<string> s;
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a.size()-i; j++){
			string b = a.substr(j, i+1);
			s.insert(b);
		}
	}
	cout << s.size();
}
