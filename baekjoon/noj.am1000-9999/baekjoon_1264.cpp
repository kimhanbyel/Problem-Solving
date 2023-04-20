#include <iostream>
#include <algorithm>
using namespace std;

int ans;
string s, mo="AEIOUaeiou";
int main(){
	while(1){
		ans = 0;
		getline(cin, s);
		if(s=="#") return 0;
		for(auto a:s){
			for(auto b:mo){
				if(a==b){
					ans++;
					break;
				}
			}
		}
				
		cout << ans << "\n";
	}
}