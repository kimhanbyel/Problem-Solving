#include <iostream>
using namespace std;

int n;
string a;
int main(){
	cin >> n;
	cin.ignore();
	for(int i=1; i<=n; i++){
		getline(cin, a);
		cin.clear();
		cout << i << ". " << a << "\n";
	}
}