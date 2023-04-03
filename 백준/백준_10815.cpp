#include <iostream>
using namespace std;

int a, n, arr[20000001];
int main(){
	cin >> n;
	while(n--){
		cin >> a;
		arr[a+10000000]++;
	}
	cin >> n;
	while(n--){
		cin >> a;
		cout << arr[a+10000000] << " ";
	}
}
