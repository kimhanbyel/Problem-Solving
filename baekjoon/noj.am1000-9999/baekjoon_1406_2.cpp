#include <iostream>
#include <list>
using namespace std;

int m;
list<char> L;
int main(){
	char input = ' ';
	string s = " ";
	cin >> s;
	 
	for(auto c : s)
		L.push_back(c);
	
	auto curser = L.end();
		
	cin >> m;
	while(m--){
		cin >> input;
		
		if(input == 'P'){
			char text;
			cin >> text;
			L.insert(curser, text);
		}
		
		else if(input == 'B'){
			if(curser != L.begin()){
				curser--;
				curser = L.erase(curser);
			}
		}
			
		else if(input == 'L'){
			if(curser != L.begin()){
				curser--;
			}
		}
		
		else if(input == 'D'){
			if(curser != L.end()){
				curser++;
			}
		}
			
//		for(auto out : L)
//		cout << out;
//		cout << '\n';
	}
	
	for(auto out : L)
		cout << out;
}
