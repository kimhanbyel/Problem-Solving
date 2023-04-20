#include <iostream>
#include <set>
using namespace std;

int a, n, m, cnt;
int main(){
	set<int> s1, s2;
	cin >> n >> m;
	for(int i=0; i<n+m; i++){
		cin >> a;
		if(i<n) s1.insert(a);
		else  s2.insert(a);
	}
	
	for(auto f : s1)
		if(s2.find(f)==s2.end())
			cnt++;
	for(auto f : s2)
		if(s1.find(f)==s1.end())
			cnt++;
			
	cout << cnt;
}
