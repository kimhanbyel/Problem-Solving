#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int a, b, c, n;
list<int> l;
int main(){
	cin >> a >> b;
	for(int i=0; i<a+b; i++){
		cin >> n;
		l.push_back(n);
	}
	l.sort();
	l.unique();
	
	cout << l.size()-(a+b-l.size());
} 
