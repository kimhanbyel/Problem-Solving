#include <iostream>
using namespace std;

int main(){
	int n, k, s, y, r[2][7]={}, a=0;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> s >> y;
		r[s][y]++;
		if(r[s][y]%k == 1) a++;
	}
	cout << a;
}
