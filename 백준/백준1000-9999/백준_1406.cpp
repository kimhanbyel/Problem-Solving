#include <iostream>
#include <list>
using namespace std;

int time;
char q=' ', v=' ', text[100001]={};
list<char> a;
list<char>::iterator iter;

void p(){
	for(iter = a.begin(); iter != a.end(); iter++)
		cout << *iter;
}
void f(){
	cin >> q;
	if(q == 'L')
		if(iter != a.begin()) iter--;
	else if(q == 'D')
		if(iter != a.end()) iter++;
	else if(q == 'B'){
		a.erase(iter);
	}
	else if(q == 'P'){
		a.push_back(v);
		iter++; 
	}
	
	p();
}

int main(){
	cin >> text;
	for(int i=0; text[i]!='\0'; i++)
		a.push_back(text[i]);
		
	iter = a.end();
	cin >> time; time++;
	
	while(time--)
		f();
}
