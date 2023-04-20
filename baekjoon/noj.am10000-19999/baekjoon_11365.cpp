#include <iostream>
#include <algorithm>
using namespace std;

string s;
int main(){
	while(1){
		getline(cin, s);
		if(s=="END") return 0;
		reverse(s.begin(), s.end());
		cout << s << "\n";
	}
}