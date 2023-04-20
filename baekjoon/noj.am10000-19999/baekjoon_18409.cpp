#include <iostream>
#include <string>
using namespace std;

int n, ans=0;
string s = "aiueo";
char c[51]={};
int main(){
	cin >> n >> c;
	for(int i=0; i<n; i++)
		for(auto check:s)
			if(c[i] == check)
				ans++;
		
	cout << ans;
}