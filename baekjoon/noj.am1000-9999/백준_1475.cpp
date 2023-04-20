#include <iostream>
#define a69 (a[6]+a[9])
using namespace std;

int main(){
	int ans=0, a[10]={};
	string s;
	cin >> s;
	for(auto n : s){
		if(++a[n-'0'] && (n!='6' && n!='9'))
			ans = max(a[n-'0'], ans);
			ans = max(a69/2+a69%2, ans);
	}
	cout << ans;
}
