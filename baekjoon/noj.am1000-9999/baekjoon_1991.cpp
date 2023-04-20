#include <iostream>
#include <vector>
using namespace std;

int n;
char root, nodeL, nodeR;
vector<pair<char, char>> v(26);
void prev(char node){
	if(node == '.') return;
	
	cout << node;
	prev(v[node].first);
	prev(v[node].second);
}

void in(char node){
	if(node == '.') return;
	
	in(v[node].first);
	cout << node;
	in(v[node].second);
}

void post(char node){
	if(node == '.') return;
	
	post(v[node].first);
	post(v[node].second);
	cout << node;
}

int main(){
	cin >> n;
	while(n--){
		cin >> root >> nodeL >> nodeR;
		v[root].first = nodeL;
		v[root].second = nodeR;
	}
	
	// A ~ Z 까지
	prev('A');
	cout << '\n';
	
	in('A');
	cout << '\n';
	
	post('A');
}